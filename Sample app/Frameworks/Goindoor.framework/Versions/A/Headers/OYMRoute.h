//
//  OYMRoute.h
//  Goindoor
//
//  Created by onyourmap on 19/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTE_H
#define INDOOR_OYMROUTE_H

#import <Foundation/Foundation.h>

#import "OYMUtils.h"

#import "OYMJsonProtocol.h"
#import "OYMRouteProjectedPoint.h"
@class OYMRouteProjectedPoint;
#import "OYMRoutingResult.h"
@class OYMRoutingResult;
#import "OYMInstruction.h"


/**
 *  This class includes the resulting route.
 */
@interface OYMRoute : NSObject <OYMJsonProtocol>

/** List of OYMRoutePoint containing the route */
@property (readonly) NSArray* route;
/** List of OYMInstruction to follow */
@property (readonly) NSArray* instructions;
/** Route distance in meters */
@property (readonly) NSNumber* distance;
/** Route time in seconds */
@property (readonly) NSNumber* time;
/** Flag telling whether the properties are fulfilled to compute the route */
@property (readonly) BOOL arePropsFulfilled;

#pragma mark Constructors
/**
 *  Route constructor.
 *
 * @param r List of OYMRoutePoint containing the list
 * @param i List of OYMInstruction
 * @param d Route distance [meters]
 * @param t Route time [seconds]
 */
- (instancetype) initWithRoute:(NSArray*)r andInstructions:(NSArray*)i andDistance:(NSNumber*)d andTime:(NSNumber*)t andProps:(BOOL)props;


#pragma mark Instance methods
/**
 *  This method returns the next instruction to be shown according to the user position.
 *
 * @param loc Current user position
 * @return The next instruction to be shown, <tt>nil</tt> if not available
 */
- (OYMInstruction*) getRouteInstructionForLocation:(OYMLocationResult*)loc;
/**
 *  This method returns the projection of the user position to the route.
 *
 * @param loc Current user position
 * @return The projected point into the route
 */
- (OYMRouteProjectedPoint*) getProjectedPointForLocation:(OYMLocationResult*)loc;
/**
 *  This method returns a RoutingResult object to be used.
 *
 * @param loc Current user position
 * @return An object including all the relevant information
 */
- (OYMRoutingResult*) getProjectionForLocation:(OYMLocationResult*)loc;
/**
 *  This metod returns a loggable representation of the route.
 *
 * @return JSON containing the required info to recreate the route 
 */
- (NSString*) logString;

@end
#endif