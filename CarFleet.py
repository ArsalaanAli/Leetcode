class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [[position[i], speed[i]] for i in range(len(position))]
        cars = sorted(cars)
        for car in cars:
            tte = (target-car[0])/car[1]
            car[1] = tte
        fleets = 1
        for i in range(len(cars)-2, -1, -1):
            if cars[i][1] <= cars[i+1][1]:
                cars[i][1] = cars[i+1][1]
            else:
                print(cars[i], cars[i+1])
                fleets+=1
        return fleets