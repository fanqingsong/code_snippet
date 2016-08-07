
module("wiseman", package.seeall)


country = "My country"


local function makeEnvDependFunc(f)
	local oldfenv = getfenv(f)

    -- 缓存所有的env
	local envTbl = {}

	table.insert( envTbl, oldfenv )

	-- environment, and isprior
	local addNewEnv = function( env, isprior )
		if isprior then
			table.insert(envTbl, 1, env)
		else
			table.insert(envTbl, env)
		end
	end

	local deleteNewEnv = function(targetEnv)
		for i,env in ipairs(envTbl) do
			if targetEnv == env then
				table.remove(envTbl, i)
			end
		end
	end

	local indexEnvTbl = function(env, key)
        for i,env in ipairs(envTbl) do
            local val = env[key]
            if val then
                return val
            end
        end

        return nil
	end

	local envMetaTable = {__index=indexEnvTbl}
    local newfenv = {}
    setmetatable(newfenv, envMetaTable)


	local fwrapper = function()
		addNewEnv(getfenv(2), true)

		setfenv(f, newfenv)

		local ret = f()

		deleteNewEnv(getfenv(2))

		setfenv(f, oldfenv)

		return ret
	end

    return fwrapper
end

--[[
function SayHello()
    local env = getfenv(1)

	local country_senario = country

    local env_caller = getfenv(2)
    if env_caller and env_caller.country then
		country_senario = env_caller.country
    end


    print(country_senario .." is a great country!")
end
]]

-- 此时 country 还是指本module， My Country
function SayHello_Naive()
    print(country .." is a great country!")
end

SayHello = makeEnvDependFunc(SayHello_Naive)





