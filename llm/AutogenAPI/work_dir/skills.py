

##### Begin of generate_image #####

from openai import OpenAI

def generate_image(prompt):
    client = OpenAI(api_key="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")
    response = client.images.generate(
        model="dall-e-3",
        prompt=prompt,
        size="1024x1024",
        quality="standard",
        n=1,
    )
    image_url = response.data[0].url
    return image_url

# 使用示例
prompt = "a white siamese cat"
image_url = generate_image(prompt)
print(image_url)


#### End of generate_image ####

        