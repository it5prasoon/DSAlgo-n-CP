from collections import defaultdict
from multiprocessing import Pool
import math
import pandas as pd
import numpy as np


def inputRead(filename):
    with open(filename,"r") as f:
        lines = [line.replace("\n","") for line in f.readlines()]
        line_1 = lines[0].split(" ")
        duration = int(line_1[0])
        n_intrsctn = int(line_1[1])
        intrsctn = list(range(n_intrsctn))
        n_streets = int(line_1[2])
        n_cars = int(line_1[3])
        bonus_points = int(line_1[4])

        streets = []
        for i in range(1, 1 + n_streets):
            street_data = lines[i].split(" ")
            inter_start = street_data[0]
            inter_end = street_data[1]
            street_name = street_data[2]
            street_duration = street_data[3]
            streets.append((inter_start, inter_end, street_name, street_duration))

        paths = []
        for i in range(1 + n_streets, 1 + n_streets + n_cars):
            path_data = lines[i].split(" ")
            paths.append(path_data[1:])


    return duration, n_intrsctn, streets, paths, bonus_points




if __name__ == '__main__':

    filename = "data/f.txt"
    print(filename)

    duration, n_intrsctn, streets, paths, bonus_points = inputRead(filename)

    # Get the frequency of the street visits
    street_freq = defaultdict(int)
    for car_path in paths:
        for visited_street in car_path[:-1]:
            street_freq[visited_street] += 1

    light_interval_factor = 20

    intrsctn = {}

    
    for i in range(n_intrsctn):
        streets_in = [street[2] for street in streets if int(street[1]) == i]
        intrsctn[i] = {street: street_freq[street] for street in streets_in if street_freq[street] > 0}


    for key in intrsctn.keys():
        values = intrsctn[key].values()
        if len(values) == 0: continue
        min_visited = min(values)
        for street in intrsctn[key].keys():
            intrsctn[key][street] = round(intrsctn[key][street] / min_visited)

        values = intrsctn[key].values()
        sum_visited_after = sum(values)
        if sum_visited_after > light_interval_factor:
            for street in intrsctn[key].keys():
                street_light_interval = round((intrsctn[key][street] / len(intrsctn[key])) * light_interval_factor)
                if street_light_interval == 0:
                    intrsctn[key][street] = None
                else:
                    intrsctn[key][street] = street_light_interval


    with open(f"out_{filename.replace('data/','')}", "w+") as f:
        intrsctn = {key: intrsctn[key] for key in intrsctn.keys() if len(intrsctn[key]) > 0}
        output = f"{len(intrsctn)}\n"
        for key in intrsctn.keys():
            intrsctn[key] = {street: intrsctn[key][street] for street in intrsctn[key].keys() if intrsctn[key][street] is not None}
            if len(intrsctn[key]) == 0:continue
            output += (f"{key}\n")
            output += (f"{len(intrsctn[key])}\n")
            for street in intrsctn[key].keys():
                output +=(f"{street} {intrsctn[key][street]}\n")


        f.write(output.rstrip())
