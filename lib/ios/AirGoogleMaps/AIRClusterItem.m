//
//  AIRClusterItem.m
//  AirMaps
//
//  Created by MOP on 04/08/2020.
//  Copyright © 2020 Christopher. All rights reserved.
//

#ifdef HAVE_GOOGLE_MAPS
#import "AIRClusterItem.h"

@implementation AIRClusterItem

- (instancetype) initWithPosition: (NSString *)identifier
                         location:(CLLocationCoordinate2D)position
                          iconUrl:(NSString *)iconUrl
                        iconWidth:(NSNumber *)iconWidth
{
    self = [super init];
    
    if (self) {
        self.identifier = identifier;
        self.position = position;
        self.iconUrl = iconUrl;
        self.iconWidth = iconWidth;
    }
    
    return self;
}

@end
#endif
