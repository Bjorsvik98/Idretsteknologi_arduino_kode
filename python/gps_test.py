from array import array
import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav
import gps_functions as gps

route_df = gps.df_format('Sigurd_i_granasen_1.gpx')
segment = gps.df_segment(route_df)
print(segment)
#print(segment['time'][0].second)

times = np.array([])
times = np.append(times, 0)
indexes = np.array([])
indexes = np.append(times, 0)
lap_index = lap_number = counter = 0
running = True
while running:
    stamp1min = segment['time'][counter].minute
    stamp1sec = segment['time'][counter].second + stamp1min*60
    stamp2min = segment['time'][counter+1].minute
    stamp2sec = segment['time'][counter+1].second + stamp2min*60
    time = stamp2sec - stamp1sec
    print(time)
    if (time) <= 2:
        times[lap_number] += time
    else:
        lap_index = counter
        times = np.append(times, 0)
        indexes = np.append(indexes, lap_index)
        lap_number += 1
        time = 0
    counter += 1
    # Break loop at the end
    if counter == (len(segment)-1):
        running = False

print(times)
print(indexes)