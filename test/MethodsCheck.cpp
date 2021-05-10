#include "ParseString.h"

extern "C" {
#include <ctest.h>
}

CTEST(methodsSuite, EqualsCheck1)
{
    ParseString ExParse;
    std::string str_1 = "Beda";
    std::string str_2 = "beda";
    const bool result = ExParse.Equals(str_1, str_2);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, EqualsCheck2)
{
    ParseString ExParse;
    std::string str_1 = "Beda";
    std::string str_2 = "beda2";
    const bool result = ExParse.Equals(str_1, str_2);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, EqualsCheck3)
{
    ParseString ExParse;
    std::string str_1 = "BeDa";
    std::string str_2 = "bEdA";
    const bool result = ExParse.Equals(str_1, str_2);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsWhitespaceCheck1)
{
    ParseString ExParse;
    ExParse.stringInputUser = " ";
    int index = 0;
    const bool result = ExParse.IsWhitespace(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsWhitespaceCheck2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "UJ ";
    int index = 1;
    const bool result = ExParse.IsWhitespace(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsWhitespaceCheck3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "U J";
    int index = 1;
    const bool result = ExParse.IsWhitespace(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsOpenParenthesis1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Beda(";
    int index = 4;
    const bool result = ExParse.IsOpenParenthesis(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsOpenParenthesis2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Beda)(";
    int index = 5;
    const bool result = ExParse.IsOpenParenthesis(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsOpenParenthesis3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Beda)(";
    int index = 3;
    const bool result = ExParse.IsOpenParenthesis(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsNotChar1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Beda)(";
    int index = 3;
    const bool result = ExParse.IsNotChar(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsComma1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "d2ds,s3g2gg";
    ExParse.indexStr = 3;
    const bool result = ExParse.IsComma();
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsComma2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "d2dss3g2gg";
    ExParse.indexStr = 5;
    const bool result = ExParse.IsComma();
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsNotChar2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Beda)(";
    int index = 4;
    const bool result = ExParse.IsNotChar(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsNotChar3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Be da)(";
    int index = 2;
    const bool result = ExParse.IsNotChar(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsEqualsKeyWord1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Key";

    ExParse.indexStr = 3;
    const bool result = ExParse.IsEqualsKeyWord(ExParse.stringInputUser);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsEqualsKeyWord2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "Key";

    ExParse.indexStr = 2;
    const bool result = ExParse.IsEqualsKeyWord(ExParse.stringInputUser);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsEqualsKeyWord3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "KeyMore";

    ExParse.indexStr = 3;
    const bool result = ExParse.IsEqualsKeyWord(ExParse.stringInputUser);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsEqualsKeyWord4)
{
    ParseString ExParse;
    ExParse.stringInputUser = "";

    ExParse.indexStr = 0;
    const bool result = ExParse.IsEqualsKeyWord(ExParse.stringInputUser);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsDigitalSymbol1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "12 3";
    int index = 1;
    const bool result = ExParse.IsDigitalSymbol(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsDigitalSymbol2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "1dfg 3";
    int index = 1;
    const bool result = ExParse.IsDigitalSymbol(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsDigitalSymbol3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "1dfg 3";
    int index = 4;
    const bool result = ExParse.IsDigitalSymbol(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, IsCloseParenthesis1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "134sf45 )";
    int index = 7;
    const bool result = ExParse.IsCloseParenthesis(index);
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, IsCloseParenthesis2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "134sf45 )";
    int index = 5;
    const bool result = ExParse.IsCloseParenthesis(index);
    ASSERT_FALSE(result);
}

CTEST(methodsSuite, FindNumber1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "134sf45 )";
    ExParse.indexStr = 2;
    const double expected = 1;
    const double result = ExParse.FindNumber();
    ASSERT_EQUAL(result, expected);
}

CTEST(methodsSuite, FindNumber2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "13 4sf45 )";
    ExParse.indexStr = 2;
    const double expected = 0;
    const double result = ExParse.FindNumber();
    ASSERT_EQUAL(result, expected);
}

CTEST(methodsSuite, FindNumber3)
{
    ParseString ExParse;
    ExParse.stringInputUser = "dfg";
    ExParse.indexStr = 1;
    const double expected = 1;
    const double result = ExParse.FindNumber();
    ASSERT_EQUAL(result, expected);
}

CTEST(methodsSuite, FindDigital1)
{
    ParseString ExParse;
    ExParse.stringInputUser = "d3542gdf4g4g";
    ExParse.indexStr = 7;
    const bool result = ExParse.FindDigital();
    ASSERT_TRUE(result);
}

CTEST(methodsSuite, FindDigital2)
{
    ParseString ExParse;
    ExParse.stringInputUser = "d2dss3g2gg";
    ExParse.indexStr = 3;
    const bool result = ExParse.FindDigital();
    ASSERT_FALSE(result);
}
