from docx import Document

def read_word_content(file_path):
    """
    Reads the content of a Word document (.docx) specified by the file path.

    Parameters:
    file_path (str): The path to the Word document.

    Returns:
    str: The combined text content of the document.
    """
    # Load the document from the specified file path
    doc = Document(file_path)

    # Initialize an empty list to store the paragraphs
    content = []

    # Iterate through each paragraph in the document
    for paragraph in doc.paragraphs:
        # Append the text of the paragraph to the content list
        content.append(paragraph.text)

    # Join the list of paragraphs into a single string with newline separation
    return '\n'.join(content)

# Example usage
if __name__ == "__main__":
    # Specify the path to the Word document
    file_path = '/Users/baihl/Downloads/00-AIAgent智能体实战课/AI智能体实战课程学习资料/04-微软AutoGen智能体/本地知识库接入-RAG/rag_skill/documents/eshop_design.docx'
    # Call the function to read the document content
    document_content = read_word_content(file_path)
    # Print the content of the document
    print(document_content)