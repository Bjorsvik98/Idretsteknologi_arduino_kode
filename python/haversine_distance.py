import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import haversine as hs


def haversine_dist(lat1, lon1, lat2, lon2) -> float:
    distance = hs.haversine(
        point1=(lat1, lon1),
        point2=(lat2, lon2),
        unit=hs.Unit.METERS
    )
    return np.round(distance, 2)