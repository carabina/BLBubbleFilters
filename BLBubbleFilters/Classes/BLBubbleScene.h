//
//  BLBubbleScene.h
//  Pods
//
//  Created by Founders Factory on 26/07/2016.
//
//

#import <SpriteKit/SpriteKit.h>
#import "BLBubbleNode.h"

NS_ASSUME_NONNULL_BEGIN
@class BLBubbleScene;


#pragma mark Delegate
@protocol BLBubbleSceneDelegate <NSObject>
- (void)didSelectBubble:(BLBubbleNode *)bubble
                atIndex:(NSInteger)index;
@end


#pragma mark Data Source
@protocol BLBubbleSceneDataSource <NSObject>
- (NSInteger)numberOfBubbles;
- (NSString *)textForBubbleAtIndex:(NSInteger)index;
@optional
- (SKColor * __nullable)bubbleColorForState:(BLBubbleNodeState)state;
- (UIFont * __nullable)bubbleFont;
- (SKColor * __nullable)bubbleTextColor;
@end

   
#pragma mark - Main Class
@interface BLBubbleScene : SKScene

//Delegate and Data Source
@property (nonatomic, weak) id<BLBubbleSceneDelegate> __nullable bubbleDelegate;
@property (nonatomic, weak) id<BLBubbleSceneDataSource> __nullable buddleDataSource;

//Loading
- (void)reload;

//Physics
@property (nonatomic, readonly) SKFieldNode *magneticField;

@end

NS_ASSUME_NONNULL_END