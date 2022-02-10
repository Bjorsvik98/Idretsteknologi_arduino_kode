import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav

plt.rcParams['axes.spines.top'] = False
plt.rcParams['axes.spines.right'] = False

# with open('Sigurd_i_granasen_1.gpx', 'r') as gpx_file:
with open('Topptur.gpx', 'r') as gpx_file:
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

route_df = pd.DataFrame(route_info)

distances = [np.nan]


for i in range(len(route_df)):
    if i == 0:
        continue
    else:
        distances.append(hav.haversine_dist(
            lat1=route_df.iloc[i - 1]['latitude'],
            lon1=route_df.iloc[i - 1]['longitude'],
            lat2=route_df.iloc[i]['latitude'],
            lon2=route_df.iloc[i]['longitude']
        ))

route_df['elevation_diff'] = route_df['elevation'].diff()

# print(gpx.get_nearest_location(route_df))



route_df['distance_diff'] = distances
route_df[route_df['elevation_diff'] >= 0]['elevation_diff'].sum()

route_df = route_df.fillna(0)

# print(route_df.head)

# route_df.to_csv('Sigurd_i_granasen_1.csv', index=True)
route_df.to_csv('Topptur.csv', index=True)


plt.figure(figsize=(14, 8))
plt.scatter(route_df['longitude'], route_df['latitude'], color='#101010')
plt.title('Route latitude and longitude points', size=20)

# plt.show()

