

local require = require
local setmetatable = setmetatable
local setfenv = setfenv
local getfenv = getfenv
local tostring = tostring
local print = print

module("module_mediator", package.seeall)


var_mediator = 77

--[[

local require_env = {var_mediator=33}
setmetatable(require_env, {__index=_G})

setfenv(require, require_env)
]]


local require_env = getfenv(require)

local function printTable(tbl)

	for k,v in pairs(tbl) do
		print("kay="..tostring(k) .. "  value="..tostring(v))
	end

end

print(" require_env ="..tostring(require_env))

print("----------- before require env ------------------")

printTable(require_env)

print("----------- after require env ------------------")


local module_test = require("module_test")

