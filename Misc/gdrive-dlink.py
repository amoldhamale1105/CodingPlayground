import sys

def generate_direct_download_link(sharing_link):
    # Split the input link to extract the file ID
    file_id = sharing_link.split('/d/')[1].split('/')[0]
    
    # Create the direct download link using the file ID
    direct_download_link = f"https://drive.google.com/uc?export=download&id={file_id}"
    
    return direct_download_link

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <google_drive_sharing_link>")
        sys.exit(1)

    sharing_link = sys.argv[1]
    direct_download_link = generate_direct_download_link(sharing_link)
    
    print(direct_download_link)

