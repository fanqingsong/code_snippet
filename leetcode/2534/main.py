from collections import deque
from enum import Enum
from typing import List


class Solution:
    def timeTaken(self, arrival: List[int], state: List[int]) -> List[int]:
        cnt = len(arrival)
        # print(cnt)

        waiting_in = deque()
        waiting_out = deque()

        class Action(Enum):
            IN = 0
            OUT = 1

        class GateState(Enum):
            IN = 0
            OUT = 1
            CLOSE = -1

        prev_state = GateState.CLOSE

        person_index = 0

        ans = [0] * cnt

        for time in range(0, cnt):
            # print(f'--- time = {time} ---')

            # push all legal persons into waiting queue
            while True:
                if person_index < cnt:
                    if arrival[person_index] <= time:
                        # print(f'state[person_index] = {state[person_index]}')
                        # print(f'Action.IN.value = {Action.IN.value}')
                        # print(f'Action.OUT.value = {Action.OUT.value}')
                        #
                        # print(f'state[person_index] == Action.IN = {state[person_index] == Action.IN.value}')
                        # print(f'state[person_index] == Action.OUT = {state[person_index] == Action.OUT.value}')

                        if state[person_index] == Action.IN.value:
                            waiting_in.append(person_index)
                        elif state[person_index] == Action.OUT.value:
                            waiting_out.append(person_index)

                        person_index += 1
                    else:
                        break
                else:
                    break
            #
            # print(f'waiting in = {waiting_in}')
            # print(f'waiting out = {waiting_out}')

            # for current time, pick one candidate to do action
            if prev_state == GateState.CLOSE:
                if waiting_out:
                    ans[waiting_out.popleft()] = time
                    prev_state = GateState.OUT
                elif waiting_in:
                    ans[waiting_in.popleft()] = time
                    prev_state = GateState.IN
                else:
                    prev_state = GateState.CLOSE
                    # break
            elif prev_state == GateState.IN:
                if waiting_in:
                    ans[waiting_in.popleft()] = time
                    prev_state = GateState.IN
                elif waiting_out:
                    ans[waiting_out.popleft()] = time
                    prev_state = GateState.OUT
                else:
                    prev_state = GateState.CLOSE
                    # break
            elif prev_state == GateState.OUT:
                if waiting_out:
                    ans[waiting_out.popleft()] = time
                    prev_state = GateState.OUT
                elif waiting_in:
                    ans[waiting_in.popleft()] = time
                    prev_state = GateState.IN
                else:
                    prev_state = GateState.CLOSE
                    # break

        return ans


if __name__ == "__main__":
    arrival = [0, 0, 0]
    state = [1, 0, 1]
    ret = Solution().timeTaken(arrival, state)
    print(ret)

    arrival = [0,1,1,2,4]
    state = [0,1,0,0,1]
    ret = Solution().timeTaken(arrival, state)
    print(ret)



