

var_test = 100

local testmodule = require("getfenvtest")


local function printTable(tbl)

	for k,v in pairs(tbl) do
		print("kay="..tostring(k) .. "  value="..tostring(v))
	end

end


print("-------- before test func env ------")
printTable(getfenv(testmodule.test))
print("-------- after test func env ------")


function mediator()

	testmodule.test()

end



local env = {}
env.testmodule = testmodule
env.mediatorflag = true
env.var_test = 55

setfenv(mediator, env)

mediator()


