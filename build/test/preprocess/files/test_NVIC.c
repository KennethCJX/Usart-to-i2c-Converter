#include "build/temp/_test_NVIC.c"
#include "test/support/BaseAddress.h"
#include "Core/Inc/NVIC.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"








NvicReg fakeNvic;











uintptr_t getNvicBaseAddress(){

 return (uintptr_t)&fakeNvic;

}



void setUp(void)

{

 int i;

 char *ptr = (char *)&fakeNvic;



 for(i = 0; i < sizeof(NvicReg); i++)

  ptr[i] = 0;

}



void tearDown(void)

{

}



void test_nvicEnableInterrupt_given_interruptNum_37_expect_ISER_register_1_bit_5_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ISER[1] = 0;

 nvicEnableIrq(37);

    UnityAssertEqualNumber((UNITY_INT)((1 << 5)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ISER[1])), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicEnableInterrupt_given_interruptNum_75_expect_ISER_register_2_bit_11_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ISER[2] = 0;

 nvicEnableIrq(75);

    UnityAssertEqualNumber((UNITY_INT)((1 << 11)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ISER[2])), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicDisableInterrupt_given_interruptNum_51_expect_ICER_register_1_bit_19_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ICER[1] = 0;

 nvicEnableIrq(51);

    UnityAssertEqualNumber((UNITY_INT)((1 << 19)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ICER[1])), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicDisableInterrupt_given_interruptNum_75_expect_ICER_register_2_bit_11_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ICER[2] = 0;

 nvicEnableIrq(75);

    UnityAssertEqualNumber((UNITY_INT)((1 << 11)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ICER[2])), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicEnablePendingIrq_given_interruptNum_50_expect_ISPR_register_1_bit_18_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ISPR[1] = 0;

 nvicEnableIrq(50);

    UnityAssertEqualNumber((UNITY_INT)((1 << 18)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ISPR[1])), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicEnablePendingIrq_given_interruptNum_84_expect_ISPR_register_2_bit_20_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ISPR[2] = 0;

 nvicEnableIrq(84);

    UnityAssertEqualNumber((UNITY_INT)((1 << 20)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ISPR[2])), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicDisablePendingIrq_given_interruptNum_75_expect_ISPR_register_2_bit_11_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ICPR[2] = 0;

 nvicEnableIrq(75);

    UnityAssertEqualNumber((UNITY_INT)((1 << 11)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ICPR[2])), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

}



void test_nvicDisablePendingIrq_given_interruptNum_71_expect_ISPR_register_2_bit_7_to_be_set(void)

{

 ((NvicReg *)getNvicBaseAddress())->NVIC_ICPR[2] = 0;

 nvicEnableIrq(71);

    UnityAssertEqualNumber((UNITY_INT)((1 << 7)), (UNITY_INT)((((NvicReg *)getNvicBaseAddress())->NVIC_ICPR[2])), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}
