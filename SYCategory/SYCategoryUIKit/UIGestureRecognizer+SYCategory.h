//
//  UIGestureRecognizer+SYCategory.h
//  zhangshaoyu
//
//  Created by zhangshaoyu on 16/11/25.
//  Copyright © 2016年 zhangshaoyu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIGestureRecognizer (SYCategory)

/*
 存在异常，待完善（同一步视图控制器不同视图添加手势后，只有一个有效）
/// 点击手势（点击次数默认1）
+ (void)tapRecognizer:(UIView *)view tapNumber:(NSInteger)number action:(void (^)(UITapGestureRecognizer *recognizer))action;

/// 长按手势（长按时间默认0.5）
+ (void)longPressRecognizer:(UIView *)view minimumPressDuration:(CFTimeInterval)time action:(void (^)(UILongPressGestureRecognizer *recognizer))action;

/// 拖拽手势
+ (void)panRecognizer:(UIView *)view action:(void (^)(UIPanGestureRecognizer *recognizer))action;

/// 拿捏缩放手势
+ (void)pinchRecognizer:(UIView *)view action:(void (^)(UIPinchGestureRecognizer *recognizer))action;

/// 滑动手势
+ (void)swipeRecognizer:(UIView *)view direction:(UISwipeGestureRecognizerDirection)direction action:(void (^)(UISwipeGestureRecognizer *recognizer))action;

/// 旋转手势
+ (void)rotationRecognizer:(UIView *)view action:(void (^)(UIRotationGestureRecognizer *recognizer))action;
*/

@end
