//
//  AIRClusterRenderer.h
//  AirMaps
//
//  Created by MOP on 04/08/2020.
//  Copyright © 2020 Christopher. All rights reserved.
//

#if defined(HAVE_GOOGLE_MAPS) && defined(HAVE_GOOGLE_MAPS_UTILS)

#import "AIRClusterItem.h"
#import <Foundation/Foundation.h>
#import <Google-Maps-iOS-Utils/GMUMarkerClustering.h>

#import "GMUClusterRenderer.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ LoadImageHandler)(UIImage *);

@class GMSMapView;
@class GMSMarker;

@protocol GMUCluster;
@protocol GMUClusterIconGenerator;
@protocol GMUClusterRenderer;

@interface AIRClusterRenderer : NSObject<GMUClusterRenderer>

/**
 * Animates the clusters to achieve splitting (when zooming in) and merging
 * (when zooming out) effects:
 * - splitting large clusters into smaller ones when zooming in.
 * - merging small clusters into bigger ones when zooming out.
 *
 * NOTES: the position to animate to/from for each cluster is heuristically
 * calculated by finding the first overlapping cluster. This means that:
 * - when zooming in:
 *    if a cluster on a higher zoom level is made from multiple clusters on
 *    a lower zoom level the split will only animate the new cluster from
 *    one of them.
 * - when zooming out:
 *    if a cluster on a higher zoom level is split into multiple parts to join
 *    multiple clusters at a lower zoom level, the merge will only animate
 *    the old cluster into one of them.
 * Because of these limitations, the actual cluster sizes may not add up, for
 * example people may see 3 clusters of size 3, 4, 5 joining to make up a cluster
 * of only 8 for non-hierachical clusters. And vice versa, a cluster of 8 may
 * split into 3 clusters of size 3, 4, 5. For hierarchical clusters, the numbers
 * should add up however.
 *
 * Default to YES.
 */
@property(nonatomic) BOOL animatesClusters;

/**
 * Allows setting a zIndex value for the clusters.  This becomes useful
 * when using multiple cluster data sets on the map and require a predictable
 * way of displaying multiple sets with a predictable layering order.
 *
 * If no specific zIndex is not specified during the initialization, the
 * default zIndex is '1'.  Larger zIndex values are drawn over lower ones
 * similar to the zIndex value of GMSMarkers.
 */
@property(nonatomic) int zIndex;

/** Sets to further customize the renderer. */
@property(nonatomic, nullable, weak) id<GMUClusterRendererDelegate> delegate;

- (instancetype)initWithMapView:(GMSMapView *)mapView
           clusterIconGenerator:(id<GMUClusterIconGenerator>)iconGenerator;

/**
 * If returns NO, cluster items will be expanded and rendered as normal markers.
 * Subclass can override this method to provide custom logic.
 */
- (BOOL)shouldRenderAsCluster:(id<GMUCluster>)cluster atZoom:(float)zoom;

- (void)loadImage:(NSString *)url
            width:(NSNumber *)width
          handler:(LoadImageHandler)handler;

@end

NS_ASSUME_NONNULL_END
#endif
