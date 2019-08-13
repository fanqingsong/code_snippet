

local getfenv = getfenv
local print = print

module("getfenvtest")


var_test = 1


function test()

	local env = getfenv(1)
	print("var_test="..env["var_test"])

	local env_caller = getfenv(2)
	print("env_caller[var_test]="..env_caller["var_test"])
end




test()





