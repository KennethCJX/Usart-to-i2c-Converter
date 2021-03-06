/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_nvicEnableInterrupt_given_interruptNum_37_expect_ISER_register_1_bit_5_to_be_set(void);
extern void test_nvicEnableInterrupt_given_interruptNum_75_expect_ISER_register_2_bit_11_to_be_set(void);
extern void test_nvicDisableInterrupt_given_interruptNum_51_expect_ICER_register_1_bit_19_to_be_set(void);
extern void test_nvicDisableInterrupt_given_interruptNum_75_expect_ICER_register_2_bit_11_to_be_set(void);
extern void test_nvicEnablePendingIrq_given_interruptNum_50_expect_ISPR_register_1_bit_18_to_be_set(void);
extern void test_nvicEnablePendingIrq_given_interruptNum_84_expect_ISPR_register_2_bit_20_to_be_set(void);
extern void test_nvicDisablePendingIrq_given_interruptNum_75_expect_ISPR_register_2_bit_11_to_be_set(void);
extern void test_nvicDisablePendingIrq_given_interruptNum_71_expect_ISPR_register_2_bit_7_to_be_set(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_NVIC.c");
  run_test(test_nvicEnableInterrupt_given_interruptNum_37_expect_ISER_register_1_bit_5_to_be_set, "test_nvicEnableInterrupt_given_interruptNum_37_expect_ISER_register_1_bit_5_to_be_set", 30);
  run_test(test_nvicEnableInterrupt_given_interruptNum_75_expect_ISER_register_2_bit_11_to_be_set, "test_nvicEnableInterrupt_given_interruptNum_75_expect_ISER_register_2_bit_11_to_be_set", 37);
  run_test(test_nvicDisableInterrupt_given_interruptNum_51_expect_ICER_register_1_bit_19_to_be_set, "test_nvicDisableInterrupt_given_interruptNum_51_expect_ICER_register_1_bit_19_to_be_set", 44);
  run_test(test_nvicDisableInterrupt_given_interruptNum_75_expect_ICER_register_2_bit_11_to_be_set, "test_nvicDisableInterrupt_given_interruptNum_75_expect_ICER_register_2_bit_11_to_be_set", 51);
  run_test(test_nvicEnablePendingIrq_given_interruptNum_50_expect_ISPR_register_1_bit_18_to_be_set, "test_nvicEnablePendingIrq_given_interruptNum_50_expect_ISPR_register_1_bit_18_to_be_set", 58);
  run_test(test_nvicEnablePendingIrq_given_interruptNum_84_expect_ISPR_register_2_bit_20_to_be_set, "test_nvicEnablePendingIrq_given_interruptNum_84_expect_ISPR_register_2_bit_20_to_be_set", 65);
  run_test(test_nvicDisablePendingIrq_given_interruptNum_75_expect_ISPR_register_2_bit_11_to_be_set, "test_nvicDisablePendingIrq_given_interruptNum_75_expect_ISPR_register_2_bit_11_to_be_set", 72);
  run_test(test_nvicDisablePendingIrq_given_interruptNum_71_expect_ISPR_register_2_bit_7_to_be_set, "test_nvicDisablePendingIrq_given_interruptNum_71_expect_ISPR_register_2_bit_7_to_be_set", 79);

  return UnityEnd();
}
