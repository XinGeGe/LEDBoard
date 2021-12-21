//
//  Macros.h
//  LEDBoard
//
//  Created by GeGe on 2021/12/21.
//

#ifndef Macros_h
#define Macros_h

#define SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define IS_IPHONE_4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE_6  (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

#define is_iPhoneXSerious [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0


#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )

#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)

#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)

#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

#define kApplication        [UIApplication sharedApplication]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kAppDelegate        [UIApplication sharedApplication].delegate
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]


#ifdef DEBUG
#define NSLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define NSLog(...)
#endif
//解决Xcode8+iOS10打印不全的问题
#ifdef DEBUG
#define MSLog(format, ...) printf("[%s] %s [%d行] %s\n", __TIME__, [[[NSString stringWithUTF8String: __FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#else
#define MSLog(format, ...)
#endif


#if TARGET_OS_IPHONE
//真机
#endif

#if TARGET_IPHONE_SIMULATOR
//模拟器
#endif

// 颜色
#define kRGBColor(r, g, b)     [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define kRandomColor           kRGBColor(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))

//16进制 ->#ffffff
#define kColorHexA(hexValue,a) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:a]
#define kColorHex(hexValue)            kColorHexA(hexValue,1.0)


#define kWeakSelf(type)   __weak typeof(type) weak##type = type;
#define kStrongSelf(type) __strong typeof(type) type = weak##type;

// 获取沙盒Cache路径
#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// 获取沙盒temp路径
#define kTempPath NSTemporaryDirectory()

// 获取沙盒Document路径
#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

// 判断是否为iPad
#define kISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


#define IOS_7  [[UIDevice currentDevice].systemVersion floatValue] >= 7.0
#define IOS_8  [[UIDevice currentDevice].systemVersion floatValue] >= 8.0
#define IOS_9  [[UIDevice currentDevice].systemVersion floatValue] >= 9.0
#define IOS_10 [[UIDevice currentDevice].systemVersion floatValue] >= 10.0
#define IOS_11 [[UIDevice currentDevice].systemVersion floatValue] >= 11.0
#define IOS_12 [[UIDevice currentDevice].systemVersion floatValue] >= 12.0
#define IOS_13 [[UIDevice currentDevice].systemVersion floatValue] >= 13.0
#define IOS_14 [[UIDevice currentDevice].systemVersion floatValue] >= 14.0
#define IOS_15 [[UIDevice currentDevice].systemVersion floatValue] >= 15.0



//<><><>获取通知中心<><><><><>
#define kNotificationCenter [NSNotificationCenter defaultCenter]
 
 
//<><><>设置随机颜色<><><><><>
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]


//<><><>获取图片资源<><><><><>
//读取本地图片
#define kLoadImage(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]
//定义UIImage对象
#define kIMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]
//获取图片；前面2种性能比这个高，但这个常用，assets.xcassets里的用这个吧
#define kImageName(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

//<><><>Frame操作相关<><><><><>/
//获取垂直居中的x（父的高度/2-子的高度/2）
#define CENTER_VERTICALLY(parent,child) floor((parent.frame.size.height - child.frame.size.height) / 2)
//获取水平居中的y（父的宽度/2-子的宽度/2）
#define CENTER_HORIZONTALLY(parent,child) floor((parent.frame.size.width - child.frame.size.width) / 2)
 
// example: [[UIView alloc] initWithFrame:(CGRect){CENTER_IN_PARENT(parentView,500,500),CGSizeMake(500,500)}];
#define CENTER_IN_PARENT(parent,childWidth,childHeight) CGPointMake(floor((parent.frame.size.width - childWidth) / 2),floor((parent.frame.size.height - childHeight) / 2))
#define CENTER_IN_PARENT_X(parent,childWidth) floor((parent.frame.size.width - childWidth) / 2)
#define CENTER_IN_PARENT_Y(parent,childHeight) floor((parent.frame.size.height - childHeight) / 2)
//view的宽度
#define WIDTH(view) view.frame.size.width
//view的高度
#define HEIGHT(view) view.frame.size.height
//view的x
#define X(view) view.frame.origin.x
//view的y
#define Y(view) view.frame.origin.y
//view的x
#define LEFT(view) view.frame.origin.x
//view的y
#define TOP(view) view.frame.origin.y
//view的bottom的y
#define BOTTOM(view) (view.frame.origin.y + view.frame.size.height
//view的right的x
#define RIGHT(view) (view.frame.origin.x + view.frame.size.width)


#endif /* Macros_h */
