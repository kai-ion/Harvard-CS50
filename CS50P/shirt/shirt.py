import sys
import os
from PIL import Image, ImageOps

def main() :
    check_command_line_arg()

    try :
        image = Image.open(sys.argv[1])
        ...
    except FileNotFoundError:
        sys.exit(f"Could not read {sys.argv[1]}")

    shirt = Image.open("shirt.png")

    size = shirt.size

    photo = ImageOps.fit(image, size)

    photo.paste(shirt, shirt)

    photo.save(sys.argv[2])
    ...

def check_command_line_arg() :
    if len(sys.argv) < 3 :
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3 :
        sys.exit("Too many command-line arguments")

    file1 = os.path.splitext(sys.argv[1])
    file2 = os.path.splitext(sys.argv[2])

    if check_extension(file1[1]) == False:
        sys.exit("Invalid input")
    if check_extension(file2[1]) == False:
        sys.exit("Invalid input")

    if file1[1].lower() != file2[1].lower() :
        sys.exit("Input and output have different extensions")

def check_extension(file) :
    if file in [".jpg", ".jepg", ".png"]:
        return True
    return False

if __name__ == "__main__" :
    main()