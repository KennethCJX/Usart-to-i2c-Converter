#include "unity.h"
#include <stdint.h>
#include "NVIC.h"
#include "BaseAddress.h"

//Stand in for the actual NVIC hardware registers
NvicReg fakeNvic;

/*
 * This will be called when accessing the NVIC hardware register
 * (test\support\BaseAddress.h)
 */
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
	nvic->NVIC_ISER[1] = 0;
	nvicEnableIrq(37);
    TEST_ASSERT_EQUAL(1 << 5, nvic->NVIC_ISER[1]);
}

void test_nvicEnableInterrupt_given_interruptNum_75_expect_ISER_register_2_bit_11_to_be_set(void)
{
	nvic->NVIC_ISER[2] = 0;
	nvicEnableIrq(75);
    TEST_ASSERT_EQUAL(1 << 11, nvic->NVIC_ISER[2]);
}

void test_nvicDisableInterrupt_given_interruptNum_51_expect_ICER_register_1_bit_19_to_be_set(void)
{
	nvic->NVIC_ICER[1] = 0;
	nvicEnableIrq(51);
    TEST_ASSERT_EQUAL(1 << 19, nvic->NVIC_ICER[1]);
}

void test_nvicDisableInterrupt_given_interruptNum_75_expect_ICER_register_2_bit_11_to_be_set(void)
{
	nvic->NVIC_ICER[2] = 0;
	nvicEnableIrq(75);
    TEST_ASSERT_EQUAL(1 << 11, nvic->NVIC_ICER[2]);
}

void test_nvicEnablePendingIrq_given_interruptNum_50_expect_ISPR_register_1_bit_18_to_be_set(void)
{
	nvic->NVIC_ISPR[1] = 0;
	nvicEnableIrq(50);
    TEST_ASSERT_EQUAL(1 << 18, nvic->NVIC_ISPR[1]);
}

void test_nvicEnablePendingIrq_given_interruptNum_84_expect_ISPR_register_2_bit_20_to_be_set(void)
{
	nvic->NVIC_ISPR[2] = 0;
	nvicEnableIrq(84);
    TEST_ASSERT_EQUAL(1 << 20, nvic->NVIC_ISPR[2]);
}

void test_nvicDisablePendingIrq_given_interruptNum_75_expect_ISPR_register_2_bit_11_to_be_set(void)
{
	nvic->NVIC_ICPR[2] = 0;
	nvicEnableIrq(75);
    TEST_ASSERT_EQUAL(1 << 11, nvic->NVIC_ICPR[2]);
}

void test_nvicDisablePendingIrq_given_interruptNum_71_expect_ISPR_register_2_bit_7_to_be_set(void)
{
	nvic->NVIC_ICPR[2] = 0;
	nvicEnableIrq(71);
    TEST_ASSERT_EQUAL(1 << 7, nvic->NVIC_ICPR[2]);
}
