#include <Keyboard.h>
#include <string.h>

// Function to send strings via the keyboard
void StringSend(const char* str, int len){
  for(int i = 0; i < len; i++){
    Keyboard.press(str[i]);  // Press the character key
    delay(10);               // Slight delay between keypresses
    Keyboard.releaseAll();   // Release all keys
  }
  delay(100);
  Keyboard.press(KEY_RETURN);  // Press ENTER after the string
  Keyboard.releaseAll();
}

void setup() {
  // Start the keyboard
  Keyboard.begin();
  
  // Open the Run dialog with WIN + R
  Keyboard.press(KEY_LEFT_GUI);  // Press Windows key
  Keyboard.press('r');           // Press the 'r' key
  delay(100);                    // Give it time to register
  Keyboard.releaseAll();         // Release keys

  delay(500);  // Wait for the Run dialog to open
  
  // Type "powershell" in the Run dialog
  StringSend("powershell", strlen("powershell"));
  delay(500);  // Wait for PowerShell to open

  // Command to open YouTube video
  const char* youtubeCommand = "msedge.exe --kiosk https://www.youtube.com/watch?v=o-YBDTqX_ZU --edge-kiosk-type=fullscreen ";  // Replace VIDEO_ID with the actual ID
  StringSend(youtubeCommand, strlen(youtubeCommand));
}

void loop() {
  // No code needed in the loop for this task

}
