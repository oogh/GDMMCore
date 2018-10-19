//
//  DisplayViewController.m
//  iOSDemo
//
//  Created by Andy on 2018/10/18.
//  Copyright © 2018年 Andy. All rights reserved.
//
#import "DisplayViewController.h"

@interface DisplayViewController ()

@property (strong, nonatomic) EAGLContext *context;

@end

@implementation DisplayViewController

- (id)initWithView:(UIView*)view
{
    if (self = [super init]) {
        
        self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        if (!self.context) {
            NSLog(@"Failed to create ES context");
        }
        
        GLKView *glkView = [[GLKView alloc] initWithFrame:[view bounds] context:self.context];
        glkView.drawableDepthFormat = GLKViewDrawableDepthFormat24;
        glkView.userInteractionEnabled = YES;   //启用视图交互
        glkView.multipleTouchEnabled = YES;     //启用多点触摸
        glkView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        
        self.view = glkView;
        self.preferredFramesPerSecond = 60;
        
        float scale = [[UIScreen mainScreen] scale];
        
        [EAGLContext setCurrentContext:self.context];
        surface_created();
        surface_changed([view bounds].size.width * scale, [view bounds].size.height * scale);
        
        [view addSubview:self.view];
    }
    return self;
}

- (void)viewWillLayoutSubviews {
    float scale = [[UIScreen mainScreen] scale];
    surface_changed([self.view bounds].size.width * scale, [self.view bounds].size.height * scale);
}

- (void)dealloc
{
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

#pragma mark - GLKView and GLKViewController delegate methods

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    draw_frame();
}

- (void)loadImage:(NSString*)path
{
    NSError* error;
    GLKTextureInfo* texture = [GLKTextureLoader textureWithContentsOfFile:path options:nil error:&error];
    if (error)
    {
        NSLog(@"Texture Error:%@", error);
    } else {
        GLuint name = texture.name;
        set_texture(name);
    }
}

@end
