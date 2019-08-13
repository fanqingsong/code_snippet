


local module_mediator = require("module_mediator")

var_caller = 55



local function printTable(tbl)

	for k,v in pairs(tbl) do
		print("kay="..tostring(k) .. "  value="..tostring(v))
	end

end


print("----------- module_mediator ------------------")

printTable(module_mediator)


print("----------- _G ------------------")

printTable(_G)



