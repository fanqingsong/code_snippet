import gym
env = gym.make('MountainCarContinuous-v0') # try for different environements
observation = env.reset()
for t in range(1000):
        env.render()

        print("----------------- observation")
        print(observation)

        action = env.action_space.sample()
        print("----------------- action")
        print(action)

        observation, reward, done, info = env.step(action)

        print("------------------ result")
        print(observation, reward, done, info)

        if done:
            print("Finished after {} timesteps".format(t+1))
            break
