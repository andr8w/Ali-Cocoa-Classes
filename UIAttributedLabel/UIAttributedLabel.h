//
//  UIAttributedLabel.h
//  Test-SandBox
//
//  Created by Olivier on 20/07/10.
//  Copyright 2010 AliSoftware. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

/////////////////////////////////////////////////////////////////////////////
// MARK: -
// MARK: NSMutableAttributedString Additions
/////////////////////////////////////////////////////////////////////////////

@interface NSAttributedString (CommodityConstructors)
+(id)attributedStringWithString:(NSString*)string;
+(id)attributedStringWithAttributedString:(NSAttributedString*)attrStr;
@end

@interface NSMutableAttributedString (CommodityStyleModifiers)
-(void)setFont:(UIFont*)font;
-(void)setFont:(UIFont*)font range:(NSRange)range;
-(void)setFontName:(NSString*)fontName size:(CGFloat)size;
-(void)setFontName:(NSString*)fontName size:(CGFloat)size range:(NSRange)range;
-(void)setFontFamily:(NSString*)fontFamily size:(CGFloat)size bold:(BOOL)isBold italic:(BOOL)isItalic range:(NSRange)range;

-(void)setTextColor:(UIColor*)color;
-(void)setTextColor:(UIColor*)color range:(NSRange)range;

-(void)setTextAlignment:(CTTextAlignment)alignment lineBreakMode:(CTLineBreakMode)lineBreakMode;
-(void)setTextAlignment:(CTTextAlignment)alignment lineBreakMode:(CTLineBreakMode)lineBreakMode range:(NSRange)range;
@end



/////////////////////////////////////////////////////////////////////////////
// MARK: -
// MARK: UIAttributedLabel
/////////////////////////////////////////////////////////////////////////////

#define UITextAlignmentJustify ((UITextAlignment)kCTJustifiedTextAlignment)

@interface UIAttributedLabel : UILabel {
	NSMutableAttributedString* _attributedText; //!< Internally mutable, but externally immutable copy access only
}
@property(nonatomic, copy) NSAttributedString* attributedText;
-(void)resetAttributedText; //!< rebuild the attributedString based on UILabel's text/font/color/alignment/... properties
@end
