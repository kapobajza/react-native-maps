//
//  AIRClusterRenderer.h
//  AirMaps
//
//  Created by MOP on 04/08/2020.
//  Copyright © 2020 Christopher. All rights reserved.
//

#if defined(HAVE_GOOGLE_MAPS) && defined(HAVE_GOOGLE_MAPS_UTILS)
#import <GoogleMaps/GoogleMaps.h>
#import <Google-Maps-iOS-Utils/GMUMarkerClustering.h>

@interface AIRClusterRenderer : GMUDefaultClusterRenderer

@property (nonatomic, weak) GMSMapView *mapView;

@end
#endif
