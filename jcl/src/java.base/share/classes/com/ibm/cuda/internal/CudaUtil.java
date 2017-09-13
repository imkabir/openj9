/*[INCLUDE-IF CUDA4J | Sidecar19-SE]*/
/*******************************************************************************
 * Copyright (c) 2013, 2017 IBM Corp. and others
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
package com.ibm.cuda.internal;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

public final class CudaUtil {

	public static byte[] read(InputStream input, boolean appendNull)
			throws IOException {
		ByteArrayOutputStream output = new ByteArrayOutputStream();
		byte[] buffer = new byte[8192];

		try {
			for (int len; (len = input.read(buffer)) > 0;) {
				output.write(buffer, 0, len);
			}

			if (appendNull) {
				output.write(0);
			}
		} finally {
			input.close();
		}

		return output.toByteArray();
	}

	private CudaUtil() {
		super();
	}
}