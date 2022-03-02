import gpxpy
import gpxpy.gpx
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs
import haversine_distance as hav
import gps_functions

def gps_to_light(name):
    
    # Opening GPS file:
    with open(name, 'r') as gpx_file:
        gpx = gpxpy.parse(gpx_file)
    
    # Formatting for dataframe:
    route_df = df_format(gpx)
    
    # Distances (in meter) between each sample:
    calcul