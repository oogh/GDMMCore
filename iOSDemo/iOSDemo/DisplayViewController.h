//
//  DisplayViewController.h
//  iOSDemo
//
//  Created by Andy on 2018/10/18.
//  Copyright © 2018年 Andy. All rights reserved.
//

#ifndef DisplayViewController_h
#define DisplayViewController_h

#import <GLKit/GLKit.h>
#import "jni-helper.h"

@interface DisplayViewController : GLKViewController

- (id)initWithView:(UIView*)view;
- (void)loadImage:(NSString*)path;
@end

#endif /* DisplayViewController_h */
