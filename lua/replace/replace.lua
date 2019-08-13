
--[[
/*******************************************************************************
*  Author: 
*  Date:
*  Description: set config for replace, replace by config in files of target path
*  Changes:
*******************************************************************************/
]]

local require = require
local io = io
local ipairs = ipairs
local assert = assert
local print = print
local string = string
local lfs = require"lfs"

local transFilePath = "./replaceFiles"

string.split = function(str, pat, max, regex)
    pat = pat or "\n"
    max = max or #str

    local t = {}
    local c = 1

    if #str == 0 then
        return {""}
    end

    if #pat == 0 then
        return nil
    end

    if max == 0 then
        return str
    end

    repeat
        local s, e = str:find(pat, c, not regex)
        max = max - 1
        if s and max < 0 then
            t[#t+1] = str:sub(c)
        else
            t[#t+1] = str:sub(c, s and s - 1)
        end
        c = e and e + 1 or #str + 1
    until not s or max < 0

    return t
end

------------------------------------------  parse start ------------------------------------------
local trans_vocabulary_table = {
    --["sourcevocabulary"] = "destvocabulary"
}

local function construct_vocabulary_table()
    require("config")
    
    print("parse trans_table starting .....")
    
    -- »ñļþÐ£¬ »»Ð·û  \n ºÍ\r\n
    local lineSep = "\r\n"
    if string.find(trans_table_string, "\r\n") then
        lineSep = "\r\n"
    elseif string.find(trans_table_string, "\n") then
        lineSep = "\n"
    elseif string.find(trans_table_string, "\r") then
        lineSep = "\r"
    end

    local lines = trans_table_string:split(lineSep)

    for _,line in ipairs(lines) do
        print("line="..line)


        local src, dest = string.match(line, "([%w_]+)%s+([%w_]+)")

        if src then
            print("well formed line="..line)
            
            trans_vocabulary_table[src] = dest
        end
    end
 
      print("parse trans_table ending .....")
    
end

-- parse table
construct_vocabulary_table()

------------------------------------------  parse end ------------------------------------------


------------------------------------------  read file list start ------------------------------------------
local targetFiles = {}

local function infilter(file, filters)
    if filters == nil or filters == "*" then
        return true
    end

    for _, v in pairs(filters) do
        if string.find(file, "%."..v.."$") then
            return true
        end
    end
    
    return false
end

local function splitonlast (path, sep)
    local dir, file = string.match(path,"^(.-)([^:/\\]*)$")
    return dir, file
end

function readdir(dir, filelist, filters)
    for file in lfs.dir(dir) do
        if file ~= ".." and file ~= "." then
            local f = dir.."/"..file
            if lfs.attributes(f).mode == "directory" then
                readdir(f, filelist, filters)
            else
                if infilter(file, filters) then
                    table.insert(filelist, f)
                end
            end
        end
    end
end

readdir(transFilePath, targetFiles, {"*"})

for _,file in ipairs(targetFiles) do
    --print("c file =".. file)
end

------------------------------------------  read file list end ------------------------------------------


------------------------------------------  handle file start ------------------------------------------

local function handle_file(file)
    local lineBuff = {}

    -- Ì¸ß§Â
    local fh = assert(io.open (file, "rb"))
    local contents = fh:read("*a")
    fh:close()
    --print(contents)
    for src,dest in pairs(trans_vocabulary_table) do
        print(src.."==>"..dest)
        contents = string.gsub(contents, src, dest)
    end

--[[
    -- »ñļþÐ£¬ »»Ð·û  \n ºÍ\r\n
    local lineSep = "\r\n"
    if string.find(contents, "\r\n") then
        lineSep = "\r\n"
    elseif string.find(contents, "\n") then
        lineSep = "\n"
    elseif string.find(contents, "\r") then
        lineSep = "\r"
    end

    local fileLines = string.split(contents, lineSep)

    for _,line in ipairs(fileLines) do
        --print(" handle_file line= "..line)
            
        local gotPattern = false
        for src,dest in pairs(trans_vocabulary_table) do
            --print("src="..src.."----")
            local s, e = string.find(line, "%s-%(%s-"..src.."%s-,%s-%\"")
            if s then
                print("!!!! ------- gotPattern ------- src ="..src)

                gotPattern = true

                -- the part before OssUsersrc
                local head = string.sub(line, 1, s-1)
                -- tail part = now");
                --print(head)
                local tail = string.sub(line, e+1)
                --print("tail="..tail)
                --print("tail[1]="..string.sub(tail, 1,1))

                -- OssUserLogType(LOG_LEVEL_NOTICE, LOG_TYPE_SYSTEM, "the system will reboot now");
                local level = dest["level"]
                local types = dest["types"]
                local msg = dest["msg"]

                local sep = " "
                if msg == "" then
                    sep = ""                
                elseif string.sub(tail, 1,1) == "\"" then
                    sep = ""
                end
                --print("msg="..msg.."sep="..sep.."--")
                local transLine = head .. "OssUserLogType(" .. level ..", " .. types .. ", \"" .. msg .. sep .. tail

                table.insert(lineBuff, transLine)

                if gotPattern then
                    break
                end

            end
        end

        if not gotPattern then
            table.insert(lineBuff, line)
        end
    end
    
]]
    --write buff to orig file
    local fh = assert(io.open(file, "wb"))
    fh:write(contents)
    fh:close()
end

for _,file in ipairs(targetFiles) do
    print("handling file =".. file)
    handle_file(file)
end

------------------------------------------  handle file end ------------------------------------------







