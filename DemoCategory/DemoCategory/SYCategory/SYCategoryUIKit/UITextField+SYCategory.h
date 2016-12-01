//
//  UITextField+SYCategory.h
//  zhangshaoyu
//
//  Created by zhangshaoyu on 16/11/28.
//  Copyright © 2016年 zhangshaoyu. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 间距（左侧，或右侧）
typedef NS_ENUM(NSInteger, TextFieldViewModeType)
{
    /// 左侧
    TextFieldViewModeTypeLeft = 1,
    
    /// 右侧
    TextFieldViewModeTypeRight = 2
};

@interface UITextField (SYCategory)

/// 设置TextField空白间隙，左侧或右侧（默认10个间距）
- (void)viewModeType:(TextFieldViewModeType)type;

#pragma mark - 输入限制（回调方法中使用“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”）

/**
 *  手机号输入限制（异常：中文联想字能被输入）
 *
 *  回调方法“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”中使用
 *
 *  @param range  当前输入区间
 *  @param string 当前输入字符
 *
 *  @return BOOL
 */
- (BOOL)limitMoblieShouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

/**
 *  数字输入限制（异常：中文联想字能被输入）
 *
 *  回调方法“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”中使用
 *
 *  @param range         当前输入区间
 *  @param string        当前输入字符
 *  @param integerLength 整数位数，0时无限制
 *  @param greater       整数首位是否大于0
 *  @param decimal       是否带小数
 *  @param decimalLength 小数位数
 *
 *  @return BOOL
 */
- (BOOL)limitNumberShouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string integer:(NSInteger)integerLength greaterThanZero:(BOOL)greater decimalPoint:(BOOL)decimal decimalDigits:(NSInteger)decimalLength;

/**
 *  第N位限制不能输入指定字符（异常：中文联想字能被输入）
 *
 *  回调方法“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”中使用
 *
 *  @param range  当前输入区间
 *  @param string 当前输入字符
 *  @param limits 限制不能输入的字符
 *  @param index  限制的第N位
 *
 *  @return BOOL
 */
- (BOOL)limitCharacterShouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string limitCharacters:(NSString *)limits limitIndex:(NSInteger)index;

/**
 *  限制输入长度（异常：中文联想字能被输入）
 *
 *  回调方法“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”中使用
 *
 *  @param maxLength 限制最大输入长度
 *  @param range     当前输入区间
 *  @param string    当前输入字符
 *
 *  @return BOOL
 */
- (BOOL)limitLength:(int)maxLength shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

/**
 *  限制输入的字符（异常：中文联想字能被输入）
 *
 *  回调方法“- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string”中使用
 *
 *  @param string   当前正在输入的字符
 *  @param limitStr 限制输入指定的字符串
 *  @param canEdit  YES只能输入指定字符，NO只能输入指定字符外的其他字符
 *
 *  @return BOOL
 */
- (BOOL)limitTextField:(NSString *)string limitStr:(NSString *)limitStr edit:(BOOL)canEdit;

#pragma mark - 输入限制长度（需要结合通知方法中使用）

/// 限制UITextField输入的长度（不区分中英文字符，通知方法名UITextFieldTextDidChangeNotification）
- (void)limitTextFieldLength:(NSUInteger)maxLength;

/// 限制UITextField输入的长度（区分中英文字符，通知方法名UITextFieldTextDidChangeNotification）
- (void)limitTextFieldCNLength:(NSUInteger)maxLength;

#pragma mark - 属性

/// 字符输入字数限制（不需要结合通知使用）
@property (nonatomic, strong) NSNumber *limitMaxLength;

/// 字符输入限制（不需要结合通知使用）
@property (nonatomic, strong) NSString *limitText;

@end

/*
 使用说明
 - (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
 {
 //    if ([self.textField isFirstResponder])
 //    {
 //        // 无效
 //        [self.textField limitMoblieShouldChangeCharactersInRange:range replacementString:string];
 //    }
 //    return YES;
 
 //    BOOL isResult = [self.textField limitMoblieShouldChangeCharactersInRange:range replacementString:string];
 //    return isResult;
 
 //    BOOL isResult = [self.textField limitLength:12 shouldChangeCharactersInRange:range replacementString:string];
 //    return isResult;
 
 
     if ([self.textField isFirstResponder])
     {
         BOOL isResult = [self.textField limitTextFieldText:string limitStr:@"0123456789" edit:NO];
         return isResult;
     }
     
     BOOL isResult = [self.textField limitNumberShouldChangeCharactersInRange:range replacementString:string integer:5 greaterThanZero:NO decimalPoint:NO decimalDigits:5];
     return isResult;
 }
 
 
 - (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
 {
     if ([self.textField isFirstResponder])
     {
         BOOL isResult = [self.textField limitTextFieldText:string limitStr:@"0123456789" edit:NO];
         return isResult;
     }
     return YES;
 }
 
 
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textFiledEditChanged:) name:UITextFieldTextDidChangeNotification object:nil];
 - (void)textFiledEditChanged:(NSNotification *)notification
 {
     if ([self.textField isFirstResponder])
     {
         [self.textField limitTextFieldLength:10];
     }
 }
 
 */



