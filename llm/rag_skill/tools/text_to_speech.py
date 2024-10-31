
# 帮我把下面的生成一个方法，可以外部调用，同时帮我添加好英文注释


from pathlib import Path
from openai import OpenAI

# Initialize OpenAI client
client = OpenAI(api_key='sk-xxxxxxx', base_url='https://oneai.evanora.top/v1')

def generate_speech_to_file(text: str, model: str = "tts-1", voice: str = "alloy", filename: str = "speech.mp3"):
    """
    Generates a speech audio file from input text using OpenAI's text-to-speech model.

    Parameters:
        text (str): The text input to convert to speech.
        model (str): The TTS model to use (default is "tts-1").
        voice (str): The voice setting for the TTS model (default is "alloy").
        filename (str): The output file name for the generated speech audio (default is "speech.mp3").

    Returns:
        Path: The path to the generated audio file.
    """
    # Set the path to save the audio file
    output_path = Path(__file__).parent / filename

    # Generate speech using the TTS model
    response = client.audio.speech.create(
        model=model,
        voice=voice,
        input=text
    )

    # Stream the response to the specified file
    response.stream_to_file(output_path)

    return output_path


if __name__ == "__main__":
    generate_speech_to_file("欢迎来到IT大白话的AI Agent课程", "tts-1", "alloy", "speech02")
