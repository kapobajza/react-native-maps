//
//  AIRClusterRenderer.m
//  AirMaps
//
//  Created by MOP on 04/08/2020.
//  Copyright © 2020 Christopher. All rights reserved.
//

#ifdef HAVE_GOOGLE_MAPS
#import "AIRClusterRenderer.h"
#import <Google-Maps-iOS-Utils/GMUMarkerClustering.h>

@implementation AIRClusterRenderer

- (instancetype)initWithMapView:(GMSMapView *)mapView clusterIconGenerator:(id<GMUClusterIconGenerator>)iconGenerator {
    self = [super initWithMapView:mapView clusterIconGenerator:iconGenerator];
    self.mapView = mapView;
    return self;
}

- (BOOL)shouldRenderAsCluster:(id<GMUCluster>)cluster atZoom:(float)zoom {
    float maxZoom = self.mapView.maxZoom;
    return cluster.count > 4 && zoom < maxZoom - 2;
}

@end
#endif

