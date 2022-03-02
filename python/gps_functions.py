import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav

def df_format(file):
    route_info = []
    for track in file.tracks:
        for segment in track.segments:
            for point in segment.points:
                route_info.append({
                    'latitude': point.latitude,
                    'longitude': point.longitude,
                    'elevation': point.elevation,
                    'time': point.time
                })
    return pd.DataFrame(route_info)

def calculate_distances(dataframe):
    vertical_distances = [np.nan]
    distances = [np.nan]
    for i in range(len(dataframe)):
        if i == 0:
           continue
        else:
           vertical_distances.append(hav.haversine_dist(
               lat1=dataframe.iloc[i - 1]['latitude'],
               lon1=dataframe.iloc[i - 1]['longitude'],
               lat2=dataframe.iloc[i]['latitude'],
               lon2=dataframe.iloc[i]['longitude']
            ))
    dataframe['vertical_distance_diff'] = vertical_distances
    dataframe['elevation_diff'] = dataframe['elevation'].diff()
    
    
    
    return distances
    