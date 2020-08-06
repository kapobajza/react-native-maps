//
//  AIRClusterItem.h
//  AirMaps
//
//  Created by MOP on 04/08/2020.
//  Copyright © 2020 Christopher. All rights reserved.
//

#if defined(HAVE_GOOGLE_MAPS) && defined(HAVE_GOOGLE_MAPS_UTILS)
#import <Foundation/Foundation.h>
#import <Google-Maps-iOS-Utils/GMUMarkerClustering.h>

NS_ASSUME_NONNULL_BEGIN

@interface AIRClusterItem : NSObject<GMUClusterItem>

@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, readwrite) CLLocationCoordinate2D position;
@property(nonatomic, strong) NSString *iconUrl;
@property(nonatomic, strong) NSNumber *iconWidth;

- (instancetype) initWithPosition: (NSString *)identifier
                         location:(CLLocationCoordinate2D)position
                          iconUrl:(NSString *)iconUrl
                        iconWidth:(NSNumber *)iconWidth;
@end

NS_ASSUME_NONNULL_END
#endif
