//
//  AddViewController.m
//  LEDBoard
//
//  Created by GeGe on 2021/12/21.
//

#import "AddViewController.h"

#import "Masonry.h"

@interface AddViewController () {
    UIScrollView *scrollView;
}

@property (nonatomic, strong) UIView *viewScrollContainer;;

@property (nonatomic, strong) UITextField *textFieldAdd;

@property (nonatomic, strong) UIButton *buttonMenu;

@property (nonatomic, strong) UIButton *buttonSetting;

@end

@implementation AddViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self createUI];
}

- (void)createUI {
    
    scrollView = [[UIScrollView alloc] init];
    scrollView.backgroundColor = [UIColor yellowColor];
    
    [self.view addSubview:scrollView];
    [scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(self.view);
        make.width.mas_equalTo(self.view);
        make.height.mas_equalTo(self.view);
    }];
    
    _viewScrollContainer = [[UIView alloc] init];
    _viewScrollContainer.backgroundColor = [UIColor blueColor];
    [scrollView addSubview:_viewScrollContainer];
    [_viewScrollContainer mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.bottom.mas_equalTo(scrollView);
        make.width.mas_equalTo(scrollView);
    }];
    
    
    _buttonMenu = [UIButton buttonWithType:UIButtonTypeCustom];
    [_viewScrollContainer addSubview:_buttonMenu];
    [_buttonMenu mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.height.mas_equalTo(30);
        make.left.mas_equalTo(15);
        make.bottom.mas_equalTo(is_iPhoneXSerious ? 50 : 30);
    }];
    
    
    
   
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
