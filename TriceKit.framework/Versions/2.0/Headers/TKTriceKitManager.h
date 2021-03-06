#ifndef TK_TRICEKIT_MANAGER_H_INCLUDED
#define TK_TRICEKIT_MANAGER_H_INCLUDED

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>

typedef NS_ENUM(NSInteger, TKTriceKitState)
{
    TKSStopped,
    TKSStarting,
    TKSStarted,
    TKSStopping
};

@class TKZone;
@protocol TKTriceKitManagerRemoteUpdateDelegate;
@protocol TKCallbackActionType;

@interface TKTriceKitManager : NSObject

@property(atomic, readonly) TKTriceKitState triceKitState;
@property(atomic, readwrite) NSDictionary *userData;
@property(atomic, readonly) NSString *sessionUserData;
@property(atomic, readwrite, weak) id<TKTriceKitManagerRemoteUpdateDelegate> remoteUpdateDelegate;

-(void)start;
-(void)stop;
-(void)updateCache;
-(void)enteredBackground;
-(void)enteredForeground;
-(void)registerCallback:(id<TKCallbackActionType>)callback forActionType:(NSString *)actionType;

-(NSArray<TKZone *> *)allZones;

@end

#endif
