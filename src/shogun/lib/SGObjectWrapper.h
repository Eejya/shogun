/*
 * -*- coding: utf-8 -*-
 * vim: set fileencoding=utf-8
 *
 * Copyright (c) 2016, Shogun-Toolbox e.V. <shogun-team@shogun-toolbox.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Heiko Strathmann
 */
#ifndef SGOBJECT_WRAPPER_H__
#define SGOBJECT_WRAPPER_H__

#include <shogun/base/SGObject.h>
#include <shogun/lib/SGString.h>
#include <string.h>


namespace shogun
{

template<class T> class CSGObjectWrapper: public CSGObject
{
public:
	CSGObjectWrapper()
	{
		m_value = 0;
		m_value_name = NULL;
		SG_ADD(&m_value, "NULL", "Wrapped value", MS_NOT_AVAILABLE);
	}

	CSGObjectWrapper(T value, const char* value_name="")
	{
		m_value = value;
		m_value_name = value_name;
		SG_ADD(&m_value, m_value_name, "Wrapped value", MS_NOT_AVAILABLE);
	}

	virtual const char* get_name() const { return "CSGObjectWrapper"; }

private:

protected:
	T m_value;
	const char* m_value_name;

};

template class CSGObjectWrapper<SGVector<float64_t>>;


template class CSGObjectWrapper<bool>;
template class CSGObjectWrapper<char>;
template class CSGObjectWrapper<int8_t>;
template class CSGObjectWrapper<uint8_t>;
template class CSGObjectWrapper<int16_t>;
template class CSGObjectWrapper<uint16_t>;
template class CSGObjectWrapper<int32_t>;
template class CSGObjectWrapper<uint32_t>;
template class CSGObjectWrapper<int64_t>;
template class CSGObjectWrapper<uint64_t>;
template class CSGObjectWrapper<float32_t>;
template class CSGObjectWrapper<float64_t>;
template class CSGObjectWrapper<floatmax_t>;

};
#endif // SGOBJECT_WRAPPER_H__
