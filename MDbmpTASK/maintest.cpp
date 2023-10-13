//#include <iostream>
//#include <fstream>
//#include <vector>
//
//
//#pragma pack(1) // ���������� ������������ ��������
//
//// ��������� BMP �����
//struct BMPHeader {
//    uint16_t signature; //  'BM'
//    uint32_t fileSize;
//    uint16_t reserved1;
//    uint16_t reserved2;
//    uint32_t dataOffset; // �������� �� ���������� ������
//    uint32_t headerSize;
//    int32_t width;
//    int32_t height;
//    uint16_t planes;
//    uint16_t bitsPerPixel; // ������� �����
//    uint32_t compression;
//    uint32_t dataSize; // ������ ���������� ������
//    int32_t horizontalRes;
//    int32_t verticalRes;
//    uint32_t colors;
//    uint32_t importantColors;
//};
//
//#pragma pack(pop) // �����������
//
//// ���������� ������� ����������
//// �� 90 �� ������� �������
//
//void rotateImage90Degrees(std::vector<unsigned char>& pixels, int width, int height) {
//    std::vector<unsigned char> rotatedPixels(pixels.size());
//
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            int srcOffset = (y * width + x) * 3;
//            int destOffset = ((width - x - 1) * height + y) * 3;
//            rotatedPixels[destOffset] = pixels[srcOffset]; // R
//            rotatedPixels[destOffset + 1] = pixels[srcOffset + 1]; // G
//            rotatedPixels[destOffset + 2] = pixels[srcOffset + 2]; // B
//        }
//    }
//
//    pixels = rotatedPixels;
//}
//
//// ������ ������� �������
//void rotateImage90DegreesCounterClockwise(std::vector<unsigned char>& pixels, int width, int height) {
//    std::vector<unsigned char> rotatedPixels(pixels.size());
//
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            int srcOffset = (y * width + x) * 3;
//            int destOffset = (x * height + (height - y - 1)) * 3;
//            rotatedPixels[destOffset] = pixels[srcOffset]; // R
//            rotatedPixels[destOffset + 1] = pixels[srcOffset + 1]; // G
//            rotatedPixels[destOffset + 2] = pixels[srcOffset + 2]; // B
//        }
//    }
//
//    pixels = rotatedPixels;
//}
//
//// ���������� ������� �����
//void GaussianFilter(std::vector<unsigned char>& pixels, int width, int height) {
//    std::vector<unsigned char> filteredPixels(pixels.size());
//
//    // ������� ������� ������
//    double kernel[5][5] = {
//        {0.003, 0.013, 0.022, 0.013, 0.003},
//        {0.013, 0.059, 0.097, 0.059, 0.013},
//        {0.022, 0.097, 0.159, 0.097, 0.022},
//        {0.013, 0.059, 0.097, 0.059, 0.013},
//        {0.003, 0.013, 0.022, 0.013, 0.003}
//    };
//
//    int radius = 2; // ������ �������
//
//    for (int y = radius; y < height - radius; y++) {
//        for (int x = radius; x < width - radius; x++) {
//            double sumR = 0.0, sumG = 0.0, sumB = 0.0;
//
//            for (int j = -radius; j <= radius; j++) {
//                for (int i = -radius; i <= radius; i++) {
//                    int pixelOffset = ((y + j) * width + (x + i)) * 3;
//                    double weight = kernel[j + radius][i + radius];
//
//                    sumR += pixels[pixelOffset] * weight;
//                    sumG += pixels[pixelOffset + 1] * weight;
//                    sumB += pixels[pixelOffset + 2] * weight;
//                }
//            }
//
//            int offset = (y * width + x) * 3;
//            filteredPixels[offset] = static_cast<unsigned char>(sumR);
//            filteredPixels[offset + 1] = static_cast<unsigned char>(sumG);
//            filteredPixels[offset + 2] = static_cast<unsigned char>(sumB);
//        }
//    }
//
//    pixels = filteredPixels;
//}
//
//
//int main() {
//    setlocale(LC_ALL, "RU");
//
//    std::string namefile;
//    std::cout << "������� �������� �����" << std::endl;
//    std::cin >> namefile;
//
//    // ������ �����
//    std::ifstream inputFile(namefile, std::ios::binary);
//
//    if (!inputFile.is_open()) {
//        std::cout << "---�� ������� ������� ����---" << std::endl;
//        return 1;
//    }
//    else {
//        std::cout << "---���� ������� ������---" << std::endl;
//    }
//
//    // ������ ��������� 
//    BMPHeader header;
//    inputFile.read(reinterpret_cast<char*>(&header), sizeof(header));
//
//    if (header.signature != 0x4D42) { // ��������� ��������� 'BM'
//        std::cout << "---�������� ������ BMP �����---" << std::endl;
//        inputFile.close();
//        return 1;
//    }
//    else {
//        std::cout << "---���� ������� ��������---" << std::endl;
//    }
//
//    int width = header.width;
//    int height = header.height;
//    int rowSize = (width * header.bitsPerPixel / 8 + 3) & (~3);
//    char* bin = new char[header.dataOffset - 54];
//
//    // ������ �������� � ������ ��������
//    std::vector<unsigned char> pixels(height * rowSize);
//    inputFile.read(reinterpret_cast<char*>(pixels.data()), pixels.size());
//    inputFile.read(reinterpret_cast<char*>(bin), header.dataOffset - 54);
//    inputFile.close();
//
//    // �������������� 
//
//    std::string agree, bazis;
//    std::cout << "������ ����������� ��������?" << std::endl;
//    std::cin >> agree;
//    if (agree == "yes" or agree == "Yes" or agree == "da" or agree == "Da") {
//        /*rotateImage(pixels, width, height);*/
//        std::cout << "������� *1*, ���� ������ ����������� �� ������� �������" << std::endl;
//        std::cout << "������� *2*, ���� ������ ����������� ������ ������� �������" << std::endl;
//        std::cin >> bazis;
//
//        if (bazis == "1") {
//            rotateImage90Degrees(pixels, width, height);
//        }
//        else {
//            rotateImage90DegreesCounterClockwise(pixels, width, height);
//        }
//
//        // ��������� �������� ������ � ������ � ���������
//        header.width = height;
//        header.height = width;
//
//
//        // ��������� ������ �����
//        header.fileSize = sizeof(header) + pixels.size();
//
//    }
//    else {
//        std::cout << "�� ��� - ��� ���" << std::endl;
//        return 0;
//    }
//
//
//    // ���������� ������������ ����������� � "output.bmp"
//    std::ofstream outputFile("output.bmp", std::ios::binary);
//
//    if (!outputFile.is_open()) {
//        std::cout << "---�� ������� ������� ���� output.bmp---" << std::endl;
//        return 1;
//    }
//
//    // ���������� ��������� � ���������� ������
//    outputFile.write(reinterpret_cast<char*>(&header), sizeof(header));
//    outputFile.write(reinterpret_cast<char*>(bin), header.dataOffset - 54);
//    outputFile.write(reinterpret_cast<char*>(pixels.data()), pixels.size());
//    outputFile.close();
//
//    std::cout << "---BMP ���� ������� ���������� � �������� � output.bmp.---" << std::endl;
//
//    // �������� "output.bmp"
//    std::ifstream rotatedInputFile("output.bmp", std::ios::binary);
//
//    if (!rotatedInputFile.is_open()) {
//        std::cout << "---�� ������� ������� ���� output.bmp---" << std::endl;
//        return 1;
//    }
//
//    // ������ ��������� 2
//    BMPHeader rotatedHeader;
//    rotatedInputFile.read(reinterpret_cast<char*>(&rotatedHeader), sizeof(rotatedHeader));
//
//    if (rotatedHeader.signature != 0x4D42) { // 'BM' ���������
//        std::cout << "---�������� ������ BMP ����� output.bmp---" << std::endl;
//        rotatedInputFile.close();
//        return 1;
//    }
//
//    int rotatedWidth = rotatedHeader.width;
//    int rotatedHeight = rotatedHeader.height;
//    int rotatedRowSize = (rotatedWidth * rotatedHeader.bitsPerPixel / 8 + 3) & (~3);
//
//    // ������ �������� � ��������� (RowSize)
//    std::vector<unsigned char> rotatedPixels(rotatedRowSize * rotatedHeight);
//    rotatedInputFile.read(reinterpret_cast<char*>(rotatedPixels.data()), rotatedPixels.size());
//    rotatedInputFile.close();
//
//    // ��������� ������ ������
//    GaussianFilter(rotatedPixels, rotatedWidth, rotatedHeight);
//
//    // ��������� ������������ ����������� � ���� "outputG.bmp"
//    std::ofstream outputGaussianFile("outputG.bmp", std::ios::binary);
//
//    if (!outputGaussianFile.is_open()) {
//        std::cout << "---�� ������� ������� ���� outputG.bmp---" << std::endl;
//        return 1;
//    }
//
//    // ���������� ��������� � ���������� ������
//    outputGaussianFile.write(reinterpret_cast<char*>(&rotatedHeader), sizeof(rotatedHeader));
//    outputGaussianFile.write(reinterpret_cast<char*>(rotatedPixels.data()), rotatedPixels.size());
//    outputGaussianFile.close();
//
//    std::cout << "---������ ������ ������� �������� � �������� � outputG.bmp.---" << std::endl;
//
//    return 0;
//}