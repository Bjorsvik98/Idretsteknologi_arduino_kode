from array import array
import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav

# Formatting function
def df_format(filename):
    
    with open(filename, 'r') as gpx_file:
        gpx = gpxpy.parse(gpx_file)

    route_info = []
    for track in gpx.tracks:
        for segment in track.segments:
            for point in segment.points:
                route_info.append({
                    'latitude': point.latitude,
                    'longitude': point.longitude,
                    'elevation': point.elevation,
                    'time': point.time
                })
    return pd.DataFrame(route_info)

# Segment aquirement function
def df_segment(route_df):
    # Temporary variable:
    seg_temp = pd.DataFrame(columns=route_df.columns)
    
    # Getting datapoints from right longitude:
    for i in range(len(route_df)):
        if (route_df['longitude'][i] < 10.31000) and (route_df['longitude'][i] > 10.30960):
            long_rows = route_df.loc[i, :]
            seg_temp = seg_temp.append(long_rows, ignore_index=True)
            
    # Return variable:     
    segment = pd.DataFrame(columns=route_df.columns)
    
    # Getting datapoints from right latitude:
    for i in range(len(seg_temp)):
        if (seg_temp['latitude'][i] < 63.376020) and (seg_temp['latitude'][i] > 63.37520):
            lat_rows = seg_temp.loc[i, :]
            segment = segment.append(lat_rows, ignore_index=True)

    return segment



# Lap aquirement function, based on specification
def get_lap(segment, specification):
    # Collecting all laps in an array consisting of their total time and start-index
    # Operating with a margin of error of 2 seconds, because some datapoints seem to
    # fall out in the measurements
    times = np.array([])
    lap_index = lap_number = counter = 0
    while lap_index < (len(segment) + 1):
        if counter == (len(segment) + 1):
            break
        stamp1 = segment['time'][counter].second
        stamp2 = segment['time'][counter+1].second
        if (stamp2 - stamp1) <= 2:
            time = stamp2 - stamp1
            times = times.append([0, lap_index])
            times[lap_number][0] += time
        else:
            lap_index = counter
            lap_number += 1
            time = 0
        counter += 1
        
    if specification == 'fastest':
        fast_lap = pd.DataFrame(columns=segment.columns)
        i = 1
        while i > 0:
            fast_lap = fast_lap.append(segment.loc[i, :], ignore_index=True)
        lap = fast_lap
        
    elif specification == 'slowest':
        slow_lap = pd.DataFrame(columns=segment.columns)
        j = 1
        while j > 0:
            slow_lap = slow_lap.append(segment.loc[i, :], ignore_index=True)
        lap = slow_lap
        
    elif specification == 'average':
        average_lap = pd.DataFrame(columns=segment.columns)
        k = 1
        while k > 0:
            average_lap = average_lap.append(segment.loc[i, :], ignore_index=True)
        lap = average_lap
    return lap

# Distance calculating function
def calculate_distances(segment):
    # Variables:
    vertical_distances = [np.nan]
    distances = [np.nan]
    
    # Get vertical distances:
    for i in range(len(segment)):
        if i == 0:
           continue
        else:
           vertical_distances.append(hav.haversine_dist(
               lat1=segment.iloc[i - 1]['latitude'],
               lon1=segment.iloc[i - 1]['longitude'],
               lat2=segment.iloc[i]['latitude'],
               lon2=segment.iloc[i]['longitude']
            ))
           
    # Differences in vertical distance and elevation:
    segment['vertical_distance_diff'] = vertical_distances
    segment['elevation_diff'] = segment['elevation'].diff()
    
    # Calculating the inclined distances for each datapoint:
    for j in range(len(vertical_distances)):
        vert_dist = segment['vertical_distance_diff'][j]
        elevation = segment['elevation_diff'][j]
        vert_dist_sq = np.square(vert_dist)
        elevation_sq = np.sqare(elevation)
        distances.append(np.sqrt(vert_dist_sq + elevation_sq))
        
    return distances
    

