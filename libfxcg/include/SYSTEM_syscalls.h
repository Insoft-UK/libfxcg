int EnableColor( int );
int GetMainBatteryVoltage( int one );
int SMEM_FindFirst( const unsigned short*pattern, unsigned short*foundfile );
int Timer_Deinstall( int InternalTimerID );
int Timer_Install( int InternalTimerID, void*handler, int elapse );
int Timer_Start( int InternalTimerID );
int Timer_Stop( int InternalTimerID );
unsigned char GetSetupSetting( unsigned int SystemParameterNo );
void CMT_Delay_100micros( int );
void CMT_Delay_micros( int );
void DisplayMainMenu( void );
void*GetStackPtr( void );
void HourGlass( void );
void OS_InnerWait_ms( int );
void SetSetupSetting( unsigned int SystemParameterNo, unsigned char SystemParameterValue );
void SMEM_maint( int );
void TestMode( int );
void PowerOff(int displayLogo);