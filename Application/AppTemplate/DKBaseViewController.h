//
//  DKBaseViewController.h
//  AppTemplate
//
//  Created by Dmitry Klimkin on 27/2/14.
//  Copyright (c) 2014 Dmitry Klimkin. All rights reserved.
//

@import UIKit;
#import "DKModel.h"

#ifdef FREE

#import "GADBannerViewDelegate.h"
#import "GADBannerView.h"
#import "GADRequest.h"

@class GADBannerView, GADRequest;

#endif

typedef void (^SaveCompletionBlock)(BOOL isFailedToSave);

#ifdef FREE

@interface DKBaseViewController : UIViewController <GADBannerViewDelegate>

@property (strong, nonatomic) GADBannerView *adBanner;
@property (strong, nonatomic) GADRequest *request;

- (GADRequest *)createRequest;
- (void)unlockNoAdvProduct: (NSNotification *)notification;

#else

@interface DKBaseViewController : UIViewController

#endif

@property (nonatomic, strong) UISearchBar *searchBar;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) RLMNotificationToken *notification;
@property (nonatomic, strong) NSMutableArray *items;

- (void)customInit;
- (void)updateUI;
- (void)reloadData;

- (void)showCompleteIndicator;
- (void)showCompleteIndicatorWithTitle: (NSString *)title;
- (void)showErrorIndicator;
- (void)showErrorIndicatorWithTitle: (NSString *)title;
- (void)showBigBusyIndicator;
- (void)showBigBusyIndicatorWithTitle: (NSString *)title;
- (void)showSmallBusyIndicator;
- (void)showSmallBusyIndicatorWithTitle: (NSString *)title;
- (void)hideIndicator;
- (void)startNavigationTutorial;
- (void)startShowItemOptionsTutorial;
- (void)startCreateNewItemTutorialWithInfo: (NSString *)infoText;

- (void)startTutorialWithInfo: (NSString *)infoText
                      atPoint: (CGPoint)infoPoint
 withFingerprintStartingPoint: (CGPoint)startPoint
                  andEndPoint: (CGPoint)endPoint
         shouldHideBackground: (BOOL)hideBackground;

@end
