import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav

def df_format(filename):
    
    with open(filename, 'r') as gpx_file:
        gpx = gpxpy.parse(gpx_file)

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

def df_segment(route_df):
    for i in range(len(route_df)):
        if (route_df['longitude'][i] < 10.31000) and (route_df['longitude'][i] > 10.30960):
            rows = route_df.loc[i, :]
            temp = temp.append(rows, ignore_index=True)
            # df1.drop(rows.index, inplace=True)

    output = pd.DataFrame(columns=temp.columns)

    for i in range(len(temp)):
        if (temp['latitude'][i] < 63.376020) and (route_df['latitude'][i] > 63.37520):
            rows = temp.loc[i, :]
            output = output.append(rows, ignore_index=True)
            # df1.drop(rows.index, inplace=True)

    x = route_df['time'][2] -route_df['time'][1]

    output_array = pd.DataFrame(columns=temp.columns)

def calculate_distances(frame_segment):
    vertical_distances = [np.nan]
    distances = [np.nan]
    for i in range(len(frame_segment)):
        if i == 0:
           continue
        else:
           vertical_distances.append(hav.haversine_dist(
               lat1=frame_segment.iloc[i - 1]['latitude'],
               lon1=frame_segment.iloc[i - 1]['longitude'],
               lat2=frame_segment.iloc[i]['latitude'],
               lon2=frame_segment.iloc[i]['longitude']
            ))
    frame_segment['vertical_distance_diff'] = vertical_distances
    frame_segment['elevation_diff'] = frame_segment['elevation'].diff()
    
    for j in range(len(vertical_distances)):
        vert_dist = frame_segment['vertical_distance_diff'][j]
        elevation = frame_segment['elevation_diff'][j]
        vert_dist_sq = np.square(vert_dist)
        elevation_sq = np.sqare(elevation)
        distances.append(np.sqrt(vert_dist_sq + elevation_sq))
        
    return distances
    
