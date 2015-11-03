//
//  ActiveCallViewController.h
//  Antidote
//
//  Created by Chuong Vu on 7/2/15.
//  Copyright (c) 2015 dvor. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AbstractCallViewController.h"

@class ActiveCallViewController;
/**
 * This abstract controller is used during an active (audio/video) call.
 * Supports showing paused and incoming calls.
 */
@protocol ActiveCallViewControllerDelegate <NSObject>

- (void)activeCallDeclineButtonPressed:(ActiveCallViewController *)controller;
- (void)activeCallMicButtonPressed:(ActiveCallViewController *)controller;
- (void)activeCallSpeakerButtonPressed:(ActiveCallViewController *)controller;
- (void)activeCallResumeButtonPressed:(ActiveCallViewController *)controller;
- (void)activeCallVideoButtonPressed:(ActiveCallViewController *)controller;

- (void)activeCallDeclineIncomingCallButtonPressed:(ActiveCallViewController *)controller;
- (void)activeCallAnswerIncomingCallButtonPressed:(ActiveCallViewController *)controller;

@end

@protocol ActiveCallViewControllerDataSource <NSObject>

- (NSInteger)activeCallControllerNumberOfPausedCalls:(ActiveCallViewController *)controller;
- (NSString *)activeCallController:(ActiveCallViewController *)controller pausedCallerNicknameForCallAtIndex:(NSIndexPath *)indexPath;
- (NSDate *)activeCallController:(ActiveCallViewController *)controller pauseDateForCallAtIndex:(NSIndexPath *)indexPath;
- (void)activeCallController:(ActiveCallViewController *)controller resumePausedCallSelectedAtIndex:(NSIndexPath *)indexPath;
- (void)activeCallController:(ActiveCallViewController *)controller endPausedCallSelectedAtIndex:(NSIndexPath *)indexPath;

@end

@interface ActiveCallViewController : AbstractCallViewController

/**
 * Delegate for call touches.
 */
@property (weak, nonatomic) id<ActiveCallViewControllerDelegate> delegate;

/**
 * Datasource for paused calls
 */
@property (weak, nonatomic) id<ActiveCallViewControllerDataSource> dataSource;

/**
 * The duration of the call.
 */
@property (nonatomic, assign) NSTimeInterval callDuration;

/**
 * Set the microphone to be selected or not selected
 */
@property (assign, nonatomic) BOOL micSelected;

/**
 * Set the speaker to be selected or not selected
 */
@property (assign, nonatomic) BOOL speakerSelected;

/**
 * Set video button selected.
 */
@property (assign, nonatomic) BOOL videoButtonSelected;

/**
 * Set whether or not the resume button is hidden.
 */
@property (assign, nonatomic) BOOL resumeButtonHidden;


/**
 * Create an incoming call view for friend
 * @param nickname Nickname of friend
 */
- (void)createIncomingCallViewForFriend:(NSString *)nickname;

/**
 * Hide incoming call view
 */
- (void)hideIncomingCallView;

/**
 * Reload the table of paused calls.
 * Use this when there is a new change.
 */
- (void)reloadPausedCalls;

/**
 * Override this to update the UI when a call is paused by friend.
 */
- (void)friendPausedCall:(BOOL)paused NS_REQUIRES_SUPER;

@end