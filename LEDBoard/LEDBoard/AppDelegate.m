//
//  AppDelegate.m
//  LEDBoard
//
//  Created by xin on 2021/12/10.
//

#import "AppDelegate.h"

#import "AddViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    AddViewController *vc = [[AddViewController alloc] init];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    
    
    return YES;
}



@end
