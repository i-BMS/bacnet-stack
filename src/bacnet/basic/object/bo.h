/**
 * @file
 * @author Steve Karg
 * @date 2005
 * @brief Binary Output objects, customize for your use
 *
 * @section DESCRIPTION
 *
 * The Binary Output object is a command object, and the present-value
 * property uses a priority array and an enumerated 2-state data type.
 *
 * @section LICENSE
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef BACNET_BINARY_OUTPUT_H
#define BACNET_BINARY_OUTPUT_H

#include <stdbool.h>
#include <stdint.h>
/* BACnet Stack defines - first */
#include "bacnet/bacdef.h"
/* BACnet Stack API */
#include "bacnet/bacerror.h"
#include "bacnet/cov.h"
#include "bacnet/rp.h"
#include "bacnet/wp.h"

/**
 * @brief Callback for gateway write present value request
 * @param  object_instance - object-instance number of the object
 * @param  old_value - binary preset-value prior to write
 * @param  value - binary preset-value of the write
 */
typedef void (*binary_output_write_present_value_callback)(
    uint32_t object_instance, BACNET_BINARY_PV old_value,
    BACNET_BINARY_PV value);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    BACNET_STACK_EXPORT
    void Binary_Output_Init(
        void);

    BACNET_STACK_EXPORT
    void Binary_Output_Property_Lists(
        const int **pRequired,
        const int **pOptional,
        const int **pProprietary);

    BACNET_STACK_EXPORT
    bool Binary_Output_Valid_Instance(
        uint32_t object_instance);
    BACNET_STACK_EXPORT
    unsigned Binary_Output_Count(
        void);
    BACNET_STACK_EXPORT
    uint32_t Binary_Output_Index_To_Instance(
        unsigned index);
    BACNET_STACK_EXPORT
    unsigned Binary_Output_Instance_To_Index(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Object_Instance_Add(
        uint32_t instance);

    BACNET_STACK_EXPORT
    bool Binary_Output_Object_Name(
        uint32_t object_instance,
        BACNET_CHARACTER_STRING * object_name);
    BACNET_STACK_EXPORT
    bool Binary_Output_Name_Set(
        uint32_t object_instance,
        char *new_name);

    BACNET_STACK_EXPORT
    char *Binary_Output_Inactive_Text(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Inactive_Text_Set(
        uint32_t instance,
        char *new_name);
    BACNET_STACK_EXPORT
    char *Binary_Output_Active_Text(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Active_Text_Set(
        uint32_t instance,
        char *new_name);

    BACNET_STACK_EXPORT
    BACNET_BINARY_PV Binary_Output_Present_Value(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Present_Value_Set(
        uint32_t instance,
        BACNET_BINARY_PV binary_value,
        unsigned priority);
    BACNET_STACK_EXPORT
    bool Binary_Output_Present_Value_Relinquish(
        uint32_t instance,
        unsigned priority);
    BACNET_STACK_EXPORT
    unsigned Binary_Output_Present_Value_Priority(
        uint32_t object_instance);

    BACNET_STACK_EXPORT
    void Binary_Output_Write_Present_Value_Callback_Set(
        binary_output_write_present_value_callback cb);

    BACNET_STACK_EXPORT
    bool Binary_Output_Out_Of_Service(
        uint32_t instance);
    BACNET_STACK_EXPORT
    void Binary_Output_Out_Of_Service_Set(
        uint32_t object_instance,
        bool value);

    BACNET_STACK_EXPORT
    char *Binary_Output_Description(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Description_Set(
        uint32_t object_instance,
        char *text_string);

    BACNET_STACK_EXPORT
    BACNET_POLARITY Binary_Output_Polarity(
        uint32_t instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Polarity_Set(
        uint32_t object_instance,
        BACNET_POLARITY polarity);

    BACNET_STACK_EXPORT
    bool Binary_Output_Reliability_Set(
        uint32_t object_instance, BACNET_RELIABILITY value);
    BACNET_STACK_EXPORT
    BACNET_RELIABILITY Binary_Output_Reliability(
        uint32_t object_instance);

    BACNET_STACK_EXPORT
    BACNET_BINARY_PV Binary_Output_Relinquish_Default(
        uint32_t object_instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Relinquish_Default_Set(
        uint32_t object_instance,
        BACNET_BINARY_PV value);

    BACNET_STACK_EXPORT
    bool Binary_Output_Encode_Value_List(
        uint32_t object_instance,
        BACNET_PROPERTY_VALUE * value_list);
    BACNET_STACK_EXPORT
    bool Binary_Output_Change_Of_Value(
        uint32_t instance);
    BACNET_STACK_EXPORT
    void Binary_Output_Change_Of_Value_Clear(
        uint32_t instance);

    BACNET_STACK_EXPORT
    int Binary_Output_Read_Property(
        BACNET_READ_PROPERTY_DATA * rpdata);
    BACNET_STACK_EXPORT
    bool Binary_Output_Write_Property(
        BACNET_WRITE_PROPERTY_DATA * wp_data);

    BACNET_STACK_EXPORT
    uint32_t Binary_Output_Create(
        uint32_t object_instance);
    BACNET_STACK_EXPORT
    bool Binary_Output_Delete(
        uint32_t object_instance);
    BACNET_STACK_EXPORT
    void Binary_Output_Cleanup(
        void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
