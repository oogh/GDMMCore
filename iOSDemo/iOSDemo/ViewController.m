//
//  ViewController.m
//  iOSDemo
//
//  Created by Andy on 2018/10/18.
//  Copyright © 2018年 Andy. All rights reserved.
//

#import "ViewController.h"
#import "DisplayViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIView *showView;
@property (strong, nonatomic) DisplayViewController *displayViewController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // 创建GLES视图并添加
    self.displayViewController = [[DisplayViewController alloc] initWithView:self.showView];
    [self addChildViewController:self.displayViewController];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)doStart:(id)sender {
    NSString* resourcePath = [[NSBundle mainBundle] resourcePath];
    NSString* path = [resourcePath stringByAppendingString:@"/out.jpg"];
    [self.displayViewController loadImage:path];
}

@end
