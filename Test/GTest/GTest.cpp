
#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "Avm/AvmStubImpl.h"

using namespace v0::com::harman::SpeechPres;
 class ADASTest : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    // std::cout << "create adas test  =======++++++++" << '\n';
    CAdasManagerGWMv2::getInstance();

  }
  static void TearDownTestCase(){
    // std::cout << "Delete adas test  =======++++++++" << '\n';
    //SpeechMgr::GetInstance()->uninit();
  }
};

TEST_F(ADASTest,SwitchOFFAVM){
  std::string xx= "Hello , this is speech TTS test , using nomal Channel";
  EXPECT_EQ(0,m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("OFF"))));
  sleep(10);
}

TEST_F(SpeehTTSTest,SwitchONAVM){
  std::string xx= "Hello，this is speech TTS test , using navigation Channel";
  EXPECT_EQ(0,m_pCAdasManagerGWMv2->pushMessage(new MessageForQueue(2,eAvm_SWITCH, string("ON"))););
  sleep(10);
}

int _tmain(int argc, char** argv)
{
    testing::GTEST_FLAG(output) = "xml:";
    testing::GTEST_FLAG(color) = "yes";
    testing::GTEST_FLAG(print_time) = "1";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
