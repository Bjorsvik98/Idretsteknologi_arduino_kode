import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav
import gps_functions as gps 

def gps_to_light(filename, specification):

    # Open GPS-file and formatting as dataframe:
    route_df = gps.df_format(filename)
    
    # Find right segment of the track:
    segment = gps.df_segment(route_df)
    
    # Get fastest/slowest/average "lap time":
    lap = gps.get_lap(segment)
    
    # Distances (in meter) between each sample:
    distances = gps.calculate_distances(lap, specification)
    
    # Calculate light sequence based on distance:
    
    
    
    
    
    