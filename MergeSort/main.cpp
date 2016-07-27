#include <iostream>
#include <vector>

auto  merge(std::vector<int> & vector, size_t left_begin_index, size_t left_end_index, size_t right_end_index)
{
    auto left_part_size = left_end_index - left_begin_index;
    auto right_part_size = right_end_index - left_end_index;
    
    auto left_part = std::vector<int>(vector.begin() + left_begin_index, vector.begin() + left_end_index);
    auto right_part = std::vector<int>(vector.begin() + left_end_index, vector.begin() + right_end_index);
    
    unsigned int left_part_index = 0;
    unsigned int right_part_index = 0;
    for ( size_t index = left_begin_index; index < right_end_index; ++index ) {
        
        
        if ( left_part_index == left_part_size ) {
            vector[ index ] = right_part[ right_part_index++ ];
        }
        else
        if ( right_part_index == right_part_size ) {
            vector[ index ] = left_part[ left_part_index++ ];
        }
        else
        if ( left_part[ left_part_index ] > right_part[ right_part_index ] ) {
            vector[ index ] = right_part[ right_part_index++ ];
        }
        else {
            vector[ index ] = left_part[ left_part_index++ ];
        }
    }
}

auto mergeSort(std::vector<int> & vector, size_t bi, size_t ei) -> void
{
    if ( bi + 1 < ei ) {
        size_t lei = (bi + ei) / 2 + (bi + ei) % 2;
        mergeSort(vector, bi, lei);
        mergeSort(vector, lei, ei);
        merge(vector, bi, lei, ei);
    }
}

auto sort(std::vector<int> & vector)
{
    mergeSort(vector, 0, vector.size());
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> vector = {1, 3, 2, 8, 4, 6};
    
    std::ostream_iterator<int> output_iterator (std::cout, " ");
    
    copy(vector.begin(), vector.end(), output_iterator);
    
    std::cout << std::endl;
    
    sort(vector);
    
    copy(vector.begin(), vector.end(), output_iterator);
    
    std::cout << std::endl;
    
    
    return 0;
}
