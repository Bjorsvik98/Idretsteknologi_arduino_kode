import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav

plt.rcParams['axes.spines.top'] = False
plt.rcParams['axes.spines.right'] = False

with open('Sigurd_i_granasen_1.gpx', 'r') as gpx_file:
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

route_df['distance_diff'] = distances
route_df[route_df['elevation_diff'] >= 0]['elevation_diff'].sum()


route_df = route_df.fillna(0)

route_df.to_csv('Sigurd_i_granasen_1.csv', index=True)

x = 0
j = 0
temp = pd.DataFrame(columns=route_df.columns)
# output.drop(['distance_diff'])

# print(route_df.loc[5])

# output.insert(route_df.loc[5], ignore_index=True)
# print(route_df[1,1])
# print(output)

# cond = route_df['longitude'] < 1

# todo: generalisere løypesegment

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

# print(x)

# todo: sortere ut segmentene, ta hensyn til feil og usikkerhet
last_saved = 0
for i in range(len(output)-1):
    if ((output['time'][i+1] - output['time'][i]) != route_df['time'][2] -route_df['time'][1]):
        rows = output.loc[last_saved+1:i, :]
        
        print(output.loc[last_saved+1:i, :])
        last_saved = i





print(output)

plt.figure(figsize=(14, 8))
plt.plot(output['longitude'], output['latitude'], color='#101010')
plt.scatter(output['longitude'], output['latitude'], color='#101000')

plt.title('Route latitude and longitude points', size=20)

plt.show()


