
/*******************************************************************************
 * Copyright (c) 1991, 2014 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
 *******************************************************************************/

/**
 * @file
 * @ingroup GC_Structs
 */

#if !defined(JVMTIOBJECTTAGTABLEITERATOR_HPP_)
#define JVMTIOBJECTTAGTABLEITERATOR_HPP_

#include "j9.h"
#include "j9protos.h"
#include "modron.h"

#include "HashTableIterator.hpp"

/**
 * Iterate over all the object slots in a J9HashTable containing J9JVMTIObjectTag's.
 * 
 * @ingroup GC_Structs
 */
class GC_JVMTIObjectTagTableIterator
{
	GC_HashTableIterator _hashTableIterator;
	void *_lastTag;	

public:

	GC_JVMTIObjectTagTableIterator(J9HashTable *hashTable) :
		_hashTableIterator(hashTable),
		_lastTag(NULL)
	{}

	void **nextSlot();
	void removeSlot();
};

#endif /* JVMTIOBJECTTAGTABLEITERATOR_HPP_ */

