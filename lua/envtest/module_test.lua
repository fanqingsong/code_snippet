

--module(..., package.seeall)

local print = print
local getfenv = getfenv
local tostring = tostring
local getmetatable = getmetatable
local pairs = pairs

module("module_test")


local function printTable(tbl)

	for k,v in pairs(tbl) do
		print("kay="..tostring(k) .. "  value="..tostring(v))
	end

end


varone = 1

local strkey = "vartwo"


-- 本模块环境
local env = getfenv(1)

env[strkey] = 2

print("vartwo="..vartwo)

print("getfenv(1) ="..tostring( ( getfenv(1) ) ) )

print("getfenv(1) metatable="..tostring( getmetatable( getfenv(1) ) ) )

if getmetatable( getfenv(1) )  then
print("--------------- before getmetatable( getfenv(1) ) -------------")
printTable( getmetatable( getfenv(1) ) )
print("--------------- after getmetatable( getfenv(1) ) -------------")
end

-- 调用此模块的环境
local env_caller = getfenv(2)

env["env_caller"] = env_caller

print("getfenv(2) ="..tostring(getfenv(2)))

print("--------------- before env_caller -------------")
printTable( env_caller )
print("--------------- after env_caller -------------")

